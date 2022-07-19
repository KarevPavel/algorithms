//
// Created by yacopsae on 15/03/22.
//

#pragma once

#include <cstring>
#include "array_sort.hpp"
#include "utils.hpp"

#define TEN 10

template <typename T>
class RadixSort : public ArraySort<T> {
 public:
  ~RadixSort() override = default;
  void sort(T *array, size_t length) override;
};

template <typename T>
void RadixSort<T>::sort(T *array, size_t length) {
  long max_number = Utils::find_max(array, length);
  long  bit_depth = std::to_string(max_number).length();
  for (long i = 1; i <= bit_depth; i++) {
	int counting[TEN] = {0};
	for (long j = 0; j < length; j++) {
	  long r = array[j] % ((long)std::pow(10, i));
	  long bit_digit = i > 1 && r > 0 ? (r - r % ((long)std::pow(10, i - 1))) / (std::pow(10, i - 1)) : r;
	  counting[bit_digit] += 1;
	}

	for (int j = 1; j < TEN; j++)
	  counting[j] += counting[j - 1];

	long *result = new long[length]{0};

	for (long j = 0; j < length; j++) {
	  long r = array[j] % ((int)std::pow(10, i));
	  long bit_digit = i > 1 && r > 0 ? (r - r % ((int)std::pow(10, i - 1))) / (std::pow(10, i - 1)) : r;
	  counting[bit_digit] -= 1;
	}
	std::memcpy(array, result, length * sizeof(long));
	delete[]result;
  }
}