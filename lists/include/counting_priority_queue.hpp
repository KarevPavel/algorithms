//
// Created by yacopsae on 19/05/2022.
//

#pragma once

#include <cstring>
#include <utility>
#include <ostream>
#include "utils.hpp"

template <typename T>
class CountingEntry {
 public:
  explicit CountingEntry(): count(0), element(nullptr), element_count(0) {}
  explicit CountingEntry(T element): element(element), count(1), element_count(1) {}
  explicit CountingEntry(T element, int _element_count): element(element), count(1), element_count(_element_count) {}

  friend std::ostream &operator<<(std::ostream &os, const CountingEntry &entry) {
	os << "element: " << entry.element << " count: " << entry.count;
	return os;
  }

  friend std::ostream &operator<<(std::ostream &os, CountingEntry *entry) {
	if (entry == nullptr)
	  os << "element NULL";
	else
	  os << "element: " << entry->element << " count: " << entry->count;
	return os;
  }

  T element;
  int element_count;
  int count;
};

template <typename T>
class CountingPriorityQueue {
 public:
  CountingPriorityQueue():
  array(new CountingEntry<T> * [4000] { nullptr }),
  length(0),
  curr_capacity(4000) {}

  void push(T element);
  void push(T element, int count);
  CountingEntry<T> pop();
  int size();

 private:
  void resize();

  CountingEntry<T> ** array;
  int length;
  int curr_capacity;
};

//NOT TESTED
template <typename T>
void CountingPriorityQueue<T>::resize() {
  auto *new_array = new CountingEntry<T> * [(int)(length * 1.75)];
  std::memcpy(new_array, array, length * sizeof(CountingEntry<T>));
  delete[] array;
  array = new_array;
}

template <typename T>
CountingEntry<T> CountingPriorityQueue<T>::pop() {
  auto * tmp = array[--length];
  array[length] = nullptr;
  return *tmp;
}

template <typename T>
void CountingPriorityQueue<T>::push(T element, int count) {
  if (length == 0)
	array[length++] = new CountingEntry<T>(element, count);
  else {
	if (size() >= curr_capacity - 1)
	  resize();

	int founded_idx = -1;
	for (int i = length - 1; i > -1; i--) {
	  if (array[i]->count > count) {
		founded_idx = i;
		break;
	  }
	}
	int element_idx = founded_idx == -1 ? 0 : founded_idx;
	Utils::shift_array(array, element_idx, ++length);
	array[element_idx] = new CountingEntry<T>(element, count);
  }
  Utils::print_array(array, length, std::cout);
}

//BAD
template <typename T>
void CountingPriorityQueue<T>::push(T element) {
  if (length == 0)
	array[length++] = new CountingEntry<T>(element);
  else {
	if (size() >= curr_capacity - 1)
	  resize();
	bool entity_found = false;
	for (int i = length - 1; i > -1; i--) {
	  if (array[i]->element[0] == *element) {
		array[i]->count++;
		if (i >= 1 && array[i]->count > array[i - 1]->count)
		  Utils::array_swap(array, i, i - 1);
		entity_found = true;
		break;
	  }
	}
	if (!entity_found) {
	  if (size() >= curr_capacity - 1)
		resize();
	  array[length++] = new CountingEntry<T>(element);
	}
  }
  Utils::print_array(array, length, std::cout);
}

template<typename T>
int CountingPriorityQueue<T>::size() {
  return length;
}
