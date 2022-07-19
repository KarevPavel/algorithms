//
// Created by yacopsae on 15/04/2022.
//

#pragma once


#include <cstring>
#include "array_sort.hpp"
#include "utils.hpp"

template <typename T>
class BubbleSortV2 : public ArraySort<T> {
 public:
  ~BubbleSortV2() override = default;
  void sort(T *array, size_t length) override;
};

template <typename T>
void BubbleSortV2<T>::sort(T *array, size_t length) {

  long* end = array + length;
  long* curr = array + 1;
  long* bubble = curr;
  while (curr != end) {
	if (bubble == array || *bubble >= *(bubble-1)) {
	  curr++;
	  bubble = curr;
	} else {
	  int tmp = *bubble;
	  *bubble = *(bubble - 1);
	  *(bubble - 1) = tmp;
	  bubble--;
	}
  }
}