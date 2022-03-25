//
// Created by yacopsae on 21/03/22.
//

#include <map>
#include <tabulate/table.hpp>
#include <tabulate/markdown_exporter.hpp>
#include "bs_tree.hpp"
#include "avl_tree.hpp"
#include "prefix_tree.hpp"
#include "utils.hpp"


int main() {

  auto prefix_tree = new PrefixTree<int>();

  prefix_tree->insert("aaaa", new int(1));
  prefix_tree->insert("aaab", new int(1));
  prefix_tree->insert("as", new int(4));
  std::cout << "aaaa: " << *prefix_tree->get("aaaa") << std::endl;
  std::cout << "aaaa: " << *prefix_tree->get("as") << std::endl;

  /*auto *avl_tree = new AvlTree<int>();
  avl_tree->insert(8);
  avl_tree->insert(5);
  avl_tree->insert(4);
  avl_tree->insert(3);
  avl_tree->insert(2);
  avl_tree->insert(6);
  avl_tree->insert(7);
  avl_tree->insert(10);
  avl_tree->insert(11);
  std::cout << "DADAD";
  auto t = "dada";*/
}

tabulate::Table generate_table(Tree<int> *tree,
							   const std::map<std::string, size_t> &tests,
							   const std::function<int *(int)>& array_generator,
							   const std::function<std::string(int *, int, Tree<int> *)>& func);

int main2() {
  std::map<std::string, size_t> tests;
  tests["100"] = 100;
  tests["1000"] = 1000;
  tests["10000"] = 10000;
  tests["100000"] = 100000;

  std::map<std::string, Tree<int> *> random_array_tree_map;
  random_array_tree_map["BSTree"] = new BSTree<int>();
  auto *bs_tree = new BSTree<int>();

  auto random_array_table = generate_table(bs_tree,
										   tests,
										   Utils::random_array<int>,
										   Utils::test_tree_insert_random_array<Tree<int>>);

  auto asc_array_table = generate_table(bs_tree,
										tests,
										Utils::asc_array<int>,
										Utils::test_tree_insert_asc_array<Tree<int>>);

  tabulate::MarkdownExporter exporter;
  std::cout << "## ASC ARRAY" << std::endl;
  std::cout << exporter.dump(asc_array_table) << std::endl;

  std::cout << std::endl << std::endl << "## RANDOM ARRAY" << std::endl;
  std::cout << exporter.dump(random_array_table) << std::endl;


  return 0;
}

tabulate::Table generate_table(Tree<int> *tree,
							   const std::map<std::string, size_t> &tests,
							   const std::function<int *(int)>& array_generator,
							   const std::function<std::string(int *, int, Tree<int> *)>& func) {
  tabulate::Table sort_results;
  tabulate::Table::Row_t header_rows;
  header_rows.push_back("elements");
  auto headers = new std::string[3]{
	  "INSERT",
	  "SEARCH",
	  "DELETE"
  };
  for (int i = 0; i < 3; i++)
	header_rows.push_back(headers[i]);
  sort_results.add_row(header_rows);

  for (auto const &test_entry: tests) {
	tabulate::Table::Row_t result_rows;

	int element_count = test_entry.second;
	int *array = array_generator(element_count);
	test_entry.first.begin();
	result_rows.push_back(test_entry.first);
	result_rows.push_back(func(array, element_count, tree));
	result_rows.push_back(Utils::test_tree_search(array, element_count, tree));
	result_rows.push_back(Utils::test_tree_delete(array, element_count, tree));
	sort_results.add_row(result_rows);
  }
  return sort_results;
}