//
// Created by yacopsae on 04/03/22.
//

#pragma once

#include "cmath"
#include "array_sort.hpp"
#include "utils.hpp"
#include "insertion_sort.hpp"

class ShellSort: public InsertionSort {
 public:
  void sort(int array[], size_t length) override;
 private:
  void sort_pieces(int array[], size_t length);
};

void ShellSort::sort(int array[], size_t length) {
  sort_pieces(array, length);
  InsertionSort::sort(array, length);
}

/**
 * Original Shell Implementation
 * [N/2, N/4, ..., 1]
 * @param array
 * @param length
 */
void ShellSort::sort_pieces(int array[], size_t length) {
  int gaps = length / 2;
  for (int gap = 2; gap <= gaps; gap *= 2)
	for (int offset = 0; offset < gap; offset++)
	  for (int i = offset; i < length; i += gap) {
		int temp = array[i];
		int j = i;
		for (; j >= gap and array[j - gap] > array[i]; j -= gap)
		  array[j] = array[j - gap];
		array[j] = temp;
	  }
}