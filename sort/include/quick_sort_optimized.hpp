#pragma once

#include <cstring>
#include "array_sort.hpp"
#include "utils.hpp"

class OptimizedQuickSort: public OriginalQuickSort {
 public:
  void sort(int array[], size_t length) override;
 private:
  void split(int array[], int start_idx, int last_idx);
};

void OptimizedQuickSort::sort(int array[], size_t length) {
  split(array, 0, length - 1);
}

void OptimizedQuickSort::split(int array[], int start_idx, int last_idx) {
    int a = start_idx - 1;
    int pivot = array[last_idx];
    for (int m = start_idx; m <= last_idx; m++)
      if (array[m] <= pivot)
        Utils::array_swap(array, ++a, m);
	if (a - start_idx> 0)
		split(array, start_idx, a - 1);
	if (last_idx - a > 0)
		split(array, a + 1, last_idx);
}