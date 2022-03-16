//
// Created by yacopsae on 04/03/22.
//

#pragma once

#include <cstring>
#include "array_sort.hpp"
#include "utils.hpp"

class InsertionSort: public ArraySort {
 public:
  ~InsertionSort() override = default;
  void sort(long *array, size_t length) override;
};

void InsertionSort::sort(long *array, size_t length) {
  for (int i = 0; i < length; i++)
	for (int j = i; j > 0 && array[j] < array[j - 1]; j--)
	  Utils::array_swap(array, j, j - 1);
}
