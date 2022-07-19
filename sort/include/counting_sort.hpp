//
// Created by yacopsae on 14/03/22.
//

#pragma once

#include <cstring>
#include "array_sort.hpp"
#include "utils.hpp"

template <typename T>
class CountingSort : public ArraySort<T> {
 public:
  ~CountingSort() override = default;
  void sort(T *array, size_t length) override;
};

template <typename T>
void CountingSort<T>::sort(T *array, size_t length) {
  long max = Utils::find_max(array, length) + 1;
  long *counting = new long[max] { 0 };
  for (long i = 0; i < length; i++)
	counting[array[i]] += 1;

  for (long i = 1; i < max; i++)
	counting[i] = counting[i] + counting[i - 1];

  long *result = new long[length];
  for (long i = 0; i < length; i++) {
	counting[array[i]] -= 1;
	result[counting[array[i]]] = array[i];
  }
  std::memcpy(array, result, length * sizeof(long));
  delete []counting;
  delete []result;
}