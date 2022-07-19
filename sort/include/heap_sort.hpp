//
// Created by yacopsae on 07/03/22.
//

#pragma once

#include <cstring>
#include "array_sort.hpp"
#include "utils.hpp"

template <typename T>
class HeapSort : public ArraySort<T> {
 public:
  ~HeapSort() override = default;

  void sort(T *array, size_t length) override;
 private:
  void max_to_root(T array[], int root, size_t size_t);
};

template <typename T>
void HeapSort<T>::sort(T *array, size_t length) {
  for (int root = length / 2 - 1; root >= 0; root--)
	max_to_root(array, root, length);

  for (int k = length - 1; k > 0; k--) {
    Utils::array_swap(array, 0, k);
    max_to_root(array, 0, k);
  }

}

template <typename T>
void HeapSort<T>::max_to_root(T array[], int root, size_t length) {
  int left = 2 * root + 1;
  int rigth = 2 * root + 2;
  int x = root;

  if (left < length && array[left] > array[x])
	x = left;

  if (rigth < length && array[rigth] > array[x])
	x = rigth;

  if (x == root)
	return;

  Utils::array_swap(array, x, root);
  max_to_root(array, x, length);
}