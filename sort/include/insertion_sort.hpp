//
// Created by yacopsae on 04/03/22.
//

#pragma once

#include <cstring>
#include "array_sort.hpp"
#include "utils.hpp"

template <typename T>
class InsertionSort: public ArraySort<T> {
 public:
  ~InsertionSort() override = default;
  void sort(T *array, size_t length) override;
};

template <typename T>
void InsertionSort<T>::sort(T *array, size_t length) {
  for (int i = 0; i < length; i++)
	for (int j = i; j > 0 && array[j] < array[j - 1]; j--)
	  Utils::array_swap(array, j, j - 1);
}
