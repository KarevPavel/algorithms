#pragma once

#include <cstring>
#include "array_sort.hpp"
#include "utils.hpp"

class OptimizedQuickSort: public ArraySort {
 public:
  void sort(int array[], size_t length) override;
 private:
  void split(int array[], size_t length, int pivot);
};

void OptimizedQuickSort::sort(int array[], size_t length) {
  split(array, length, length - 1);
}

void split(int array[], size_t length, int pivot_idx) {
  int left = 0;
  int right = length - 1;
  while (left != right) {
	while (left < length && left <= array[pivot_idx])
	  left++;
	while (right > 0 && right > array[pivot_idx])
	  right++;
	Utils::array_swap(array, left, right);
  }
  split(array, left + 1, left - 1);
  split(array, right + 1, right);
}