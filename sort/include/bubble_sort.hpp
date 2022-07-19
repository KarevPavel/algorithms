//
// Created by yacopsae on 03/03/22.
//

#pragma once

#include <cstring>
#include "array_sort.hpp"
#include "utils.hpp"

template <typename T>
class BubbleSort : public ArraySort<T> {
 public:
  ~BubbleSort() override = default;
  void sort(T *array, size_t length) override;
};

template <typename T>
void BubbleSort<T>::sort(T *array, size_t length) {
  for (int i = 0; i < length; i++)
	for (int j = 0; j < length - i - 1; j++)
	  if (!std::is_pointer<T>::value) {
		if (array[j] > array[j + 1])
		  Utils::array_swap(array, j, j + 1);
	  } else {
		if (*array[j] > *array[j + 1])
		  Utils::array_swap(array, j, j + 1);
	  }
}



