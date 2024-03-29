//
// Created by yacopsae on 09/03/22.
//
#pragma once

#include <cstring>
#include <algorithm>
#include "array_sort.hpp"
#include "utils.hpp"

template <typename T>
class BucketSort : public ArraySort<T> {
 public:
  ~BucketSort() override = default;
  void sort(T *array, size_t length) override;
};

template <typename T>
void BucketSort<T>::sort(T *array, size_t length) {
  auto bucket = new std::vector<int>[length + 1]();

  int max = Utils::find_max(array, length);

  for (int i = 0; i < length; i++) {
	int bucket_index = std::round((float)(array[i] * length) / ((float)max + 1));
	bucket[bucket_index].push_back(array[i]);
	if (bucket[bucket_index].size() > 1)
	  std::sort(bucket[bucket_index].begin(), bucket[bucket_index].end());
  }

  int index = 0;
  for (int i = 0; i < length; i++) {
	while (!bucket[i].empty()) {
	  array[index++] = *(bucket[i].begin());
	  bucket[i].erase(bucket[i].begin());
	}
  }
  delete [] bucket;
}
