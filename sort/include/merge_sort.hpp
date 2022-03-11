//
// Created by yacopsae on 09/03/22.
//

#pragma once
#include <cstring>
#include "array_sort.hpp"
#include "utils.hpp"

class MergeSort : public ArraySort {
 public:
  void sort(int array[], size_t length) override;
 private:
  void mergeSort(int array[], int start_idx, int end_idx);
  void merge(int array[], int start_idx, int m, int end_idx);
};

void MergeSort::sort(int array[], size_t length) {
  mergeSort(array, 0, length - 1);
}

void MergeSort::merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1], R[n2];

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
}

void MergeSort::mergeSort(int arr[], int l, int r) {
  if (l < r) {
	int m = l + (r - l) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);
	merge(arr, l, m, r);
  }
}