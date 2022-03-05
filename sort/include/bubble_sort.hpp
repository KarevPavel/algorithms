//
// Created by yacopsae on 03/03/22.
//

#pragma once

#include <cstring>
#include "array_sort.hpp"
#include "utils.hpp"

class BubbleSort : public ArraySort {
 public:
  void sort(int array[], size_t length) override;
};

void BubbleSort::sort(int array[], size_t length) {
  for (int i = 0; i < length; i++)
	for (int j = 0; j < length - i - 1; j++)
	  if (array[j] > array[j + 1])
		Utils::array_swap(array, j, j + 1);
}



