//
// Created by yacopsae on 04/03/22.
//

#pragma once

#include <cstring>
#include "array_sort.hpp"
#include "utils.hpp"

class OptimizedBubbleSort : public ArraySort {
 public:
  ~OptimizedBubbleSort() override = default;
  void sort(long *array, size_t length) override;
};

void OptimizedBubbleSort::sort(long *array, size_t length) {
  for (int i = 0; i < length; i++) {
    bool is_changed = false;
	for (int j = 0; j < length - i - 1; j++)
	  if (array[j] > array[j + 1]) {
		Utils::array_swap(array, j, j + 1);
		is_changed = true;
	  }
	if (!is_changed) {
	  break;
	}
  }
}

