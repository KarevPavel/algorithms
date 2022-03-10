//
// Created by yacopsae on 09/03/22.
//
#pragma once

#include <cstring>
#include "array_sort.hpp"
#include "utils.hpp"

class BucketSort : public ArraySort {
 public:
  void sort(int array[], size_t length) override;

 private:
  int ** bucket;
};

void BucketSort::sort(int array[], size_t length) {
  int max = 1.5 * length;
  bucket = new int * [max];
  for (int i = 0; i < length; i++) {
    int bucket_index = (array[i] * length) / (max + 1);
    if (bucket[bucket_index] == nullptr)
	  bucket[bucket_index] = &array[i];
    else {
	  bucket[bucket_index] =
    }
  }

  delete bucket;
}