//
// Created by yacopsae on 15/04/2022.
//

#pragma once


#include <cstring>
#include "array_sort.hpp"
#include "utils.hpp"


class BubbleSortV2 : public ArraySort {
 public:
  ~BubbleSortV2() override = default;
  void sort(long *array, size_t length) override;
};

void BubbleSortV2::sort(long *array, size_t length) {

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