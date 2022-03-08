//
// Created by yacopsae on 07/03/22.
//

#pragma once

#include <cstring>
#include "array_sort.hpp"
#include "utils.hpp"

class SelectionSort : public ArraySort {
 public:
  void sort(int array[], size_t length) override;
};

void SelectionSort::sort(int array[], size_t length) {
  for (int i = length; i > 0; i--) {
	int max_element_idx = i;
	for (int j = 0; j < i; j++)
	  if (array[j] > array[max_element_idx])
		max_element_idx = j;
	Utils::array_swap(array, i, max_element_idx);
  }
}