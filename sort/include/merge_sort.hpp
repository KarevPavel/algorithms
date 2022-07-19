//
// Created by yacopsae on 09/03/22.
//

#pragma once
#include <cstring>
#include "array_sort.hpp"
#include "utils.hpp"

template <typename T>
class MergeSort : public ArraySort<T> {
 public:
  ~MergeSort() override = default;
  void sort(T *array, size_t length) override;
 private:
  void mergeSort(T array[], int l, int r);
  void merge(T array[], int l, int m, int r);
};

template <typename T>
void MergeSort<T>::sort(T *array, size_t length) {
  if (length < 1)
	throw std::runtime_error("length cannot be less then '1'");
  mergeSort(array, 0, length - 1);
}

template <typename T>
void MergeSort<T>::merge(T arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  long * L = new long[n1];
  long * R = new long[n2];

  for (i = 0; i < n1; i++)
	L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
	R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
	if (L[i] <= R[j])
	  arr[k] = L[i++];
	else
	  arr[k] = R[j++];
	k++;
  }

  while (i < n1)
	arr[k++] = L[i++];

  while (j < n2)
	arr[k++] = R[j++];
  delete [] R;
  delete [] L;
}

template <typename T>
void MergeSort<T>::mergeSort(T array[], int l, int r) {
  if (l < r) {
	int m = l + (r - l) / 2;
	mergeSort(array, l, m);
	mergeSort(array, m + 1, r);
	merge(array, l, m, r);
  }
}