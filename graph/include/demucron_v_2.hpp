//
// Created by yacopsae on 05/05/2022.
//
#include "utils.hpp"
#include "vector_array.hpp"
#pragma once

class Demucron {
 public:
  Demucron(int **array, int array_length) : array(array), array_length(array_length) {}

  VectorArray<int> ** sort() const {
	auto ** order = new VectorArray<int> * [array_length];
	static int order_index = 0;
	for (int *sum = col_sum(); no_zero(sum); sum = delete_zero(sum, any_zero(sum, order, order_index)));
	return order;
  }

  bool no_zero(const int * sum) const {
    for (int i = 0; i < array_length; i++)
      if (sum[i] != -1)
		return true;
	return false;
  }

  int *delete_zero(int *sum, int **zero_indices) const {
	for (int i = 0; zero_indices != nullptr && zero_indices[i] != nullptr; i++)
	  for (int col = 0; col < array_length; col++) {
		sum[col] -= array[*zero_indices[i]][col];
		sum[*zero_indices[i]] = -1;
	  }
	return sum;
  }

  int *col_sum() const {
	int *sum = new int[array_length];
	for (int col = 0; col < array_length; col++)
	  for (int row = 0; row < array_length; row++)
		sum[col] += array[row][col];
	return sum;
  }

  int **any_zero(const int *col_sum, VectorArray<int> ** final_result, int & final_result_index_level) const {
	int **result = new int *[array_length];
	int index = 0;
	for (int i = 0; i < array_length; i++)
	  if (col_sum[i] == 0) {
		result[index] = new int(i);
		if (final_result[final_result_index_level + index] == nullptr)
		  final_result[final_result_index_level + index] = new VectorArray<int>(2);
		final_result[final_result_index_level + index]->put(i);
		index++;
	  }
	final_result_index_level++;
	return result;
  }

  int **array;
  int array_length;
};