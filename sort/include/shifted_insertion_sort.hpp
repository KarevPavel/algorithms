//
// Created by yacopsae on 04/03/22.
//

#pragma once

#include <cstring>
#include "array_sort.hpp"
#include "utils.hpp"

class ShiftedInsertionSort: public ArraySort {
 public:
  void sort(int array[], size_t length) override;
};

void ShiftedInsertionSort::sort(int array[], size_t length) {

  for (int i = 0; i < length; i++)
	for (int j = i; j > 0 && array[j] < array[j - 1]; j--)
	  Utils::array_swap(array, j, j - 1);


  for (int i = 0; i < length; i++) {
    bool wanna_change = false;
	for (int j = i; j > 0; j--) {
	  int right_element_index;
	  if (!wanna_change && array[j] < array[j - 1]) {
		right_element_index = j - 1;
		wanna_change = true;
	  }
	  if (wanna_change && array[j] < array[j - 1]) {
		int right_element = array[right_element_index];
		Utils::shift_array(array, j - 1, right_element_index);
		array[j - 1] = right_element;
		Utils::print_array(array, length, std::cout);
		wanna_change = false;
	  }
	}
  }
}

