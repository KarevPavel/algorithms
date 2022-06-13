//
// Created by yacopsae on 08/06/2022.
//

#pragma once

#include <iostream>
#include <limits>
#include "counting_priority_queue.hpp"
#include "prefix_tree.hpp"
#include "simple_tree.hpp"
#include "ptr_factor_array.hpp"
#include "factor_array.hpp"

namespace Huffman {

class HuffEntry {
 public:
  HuffEntry(char *e, bool v) : _element(e), _v(v), _include_in_code_table(true) {}
  HuffEntry(char *e, bool v, bool include_in_code_table) : _element(e), _v(v), _include_in_code_table(include_in_code_table) {}

  void v(bool v) {
	this->_v = v;
  }

  bool v() {
	this->_v;
  }

  bool include_in_code_table() const {
	return this->_include_in_code_table;
  }

  char * element() {
	return _element;
  }

 private:
  char *_element;
  bool _include_in_code_table;
  bool _v;
 public:
  bool operator==(const HuffEntry &rhs) const {
	return _element == rhs._element;
  }

  bool operator!=(const HuffEntry &rhs) const {
	return !(rhs == *this);
  }

};

static void calc_codes(FactorArray<std::pair<char *, std::string>> &,
					   std::string,
					   Node<HuffEntry> *, int);

static void compress_v2(std::istream &istream, std::ostream &output) {
  char c_byte;
  auto *pr_queue = new CountingPriorityQueue<char *>();
  while (istream.get(c_byte)) {
	pr_queue->push(new char[]{c_byte});
  }

  auto *factor_array = new PtrFactorArray<Node<HuffEntry>>();
  while (pr_queue->size() > 1) {
	auto element_1 = pr_queue->pop();
	auto element_2 = pr_queue->pop();
	auto count_sum = element_1.count + element_2.count;
	int new_length = element_1.element_count + element_2.element_count;
	char *new_element = new char[new_length];
	for (int i = 0, idx = 0, j = 0; idx < new_length; i++, j++) {
	  if (i < element_1.element_count)
		new_element[idx++] = element_1.element[i];
	  if (j < element_2.element_count)
		new_element[idx++] = element_2.element[j];
	}

	auto *root = new Node<HuffEntry>(new HuffEntry(new_element, false, false));
	auto *node1 = new Node<HuffEntry>(new HuffEntry(element_1.element, false));
	auto *node2 = new Node<HuffEntry>(new HuffEntry(element_2.element, true));

	auto founded1 = factor_array->find(node1);
	if (founded1 != nullptr) {
	  delete node1;
	  node1 = founded1;
	  founded1->value()->v(false);
	}
	auto founded2 = factor_array->find(node2);
	if (founded2 != nullptr) {
	  delete node2;
	  node2 = founded2;
	  node2->value()->v(true);
	}
	root->r(node1);
	root->l(node2);
	factor_array->put(root);
	pr_queue->push(new_element, count_sum);
  }

  std::cout << "SIZE:" << factor_array->size() << std::endl;
  std::cout << "factor_array.get(0)" << factor_array->get(factor_array->size() - 1) << std::endl;

  FactorArray<std::pair<char *, std::string>> array;
  calc_codes(array, "", factor_array->get(factor_array->size() - 1), 1);

  std::cout << "ARRAY [\n";
  for (int i = 0; i < array.size(); i++)
	std::cout << array.get(i).first << " : " << array.get(i).second << "\n";
  std::cout << "]";

}

static void calc_codes(FactorArray<std::pair<char *, std::string>> & arr,
					   std::string code,
					   Node<HuffEntry> * node,
					   int iteration) {
  if (node == nullptr)
	return;
  if (iteration > 1) {
	code.push_back(node->value()->v() ? '1' : '0');
	auto pair = std::pair<char *, std::string>(node->value()->element(), code);
	arr.put(pair);
  }
  calc_codes(arr, code, node->l(), ++iteration);
  calc_codes(arr, code, node->r(), ++iteration);

}
}