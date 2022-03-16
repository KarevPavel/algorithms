//
// Created by yacopsae on 09/03/22.
//
#pragma once

#include <cstring>
#include "array_sort.hpp"
#include "utils.hpp"

class OriginalQuickSort : public ArraySort {
 public:
  ~OriginalQuickSort() override = default;
  void sort(long *array, size_t length) override;
 private:
  void split(long array[], int start_idx, int end_idx);
};

void OriginalQuickSort::sort(long *array, size_t length) {
  split(array, 0, length - 1);
}

void OriginalQuickSort::split(long array[], int start_idx, int end_idx) {
  int left = start_idx;
  int right = end_idx;
  int pivot = array[right];
  while (right > left) {
	while (left < end_idx && array[left] <= pivot)
	  left++;
	while (right > start_idx && array[right] > pivot)
	  right--;
	if (right <= left)
	  break;
	Utils::array_swap(array, left, right);
  }
  //TODO: Не уверен, что это действительно надо делать
  if (left == right)
	left--;

  if (left - start_idx > 0)
	split(array, start_idx, left);
  if (end_idx - right > 0)
	split(array, right, end_idx);
}