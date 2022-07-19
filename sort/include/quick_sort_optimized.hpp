#pragma once

#include <cstring>
#include "array_sort.hpp"
#include "utils.hpp"
#include "quick_sort_original.hpp"

template <typename T>
class OptimizedQuickSort: public OriginalQuickSort<T> {
 public:
  ~OptimizedQuickSort() override = default;
  void sort(T *array, size_t length) override;
 private:
  void split(T array[], int start_idx, int last_idx);
};

template <typename T>
void OptimizedQuickSort<T>::sort(T *array, size_t length) {
  split(array, 0, length - 1);
}

template <typename T>
void OptimizedQuickSort<T>::split(T array[], int start_idx, int last_idx) {
    int a = start_idx - 1;
    T pivot = array[last_idx];
    for (int m = start_idx; m <= last_idx; m++)
      if (array[m] <= pivot)
        Utils::array_swap(array, ++a, m);
	if (a - start_idx> 0)
		split(array, start_idx, a - 1);
	if (last_idx - a > 0)
		split(array, a + 1, last_idx);
}