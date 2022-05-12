//
// Created by yacopsae on 10/05/2022.
//

#pragma once

#include "factor_array.hpp"

class Tarjan {

 public:
  Tarjan(int **array, int array_length) : array(array), array_length(array_length) {}

  Array<int> & vertex_indexes() {
	auto visited = new bool[array_length];
	//auto result = new int [array_length];
	auto result = new FactorArray<int>(10);
	while (result->size() < array_length)
	  vertex_indexes(next_vertex(*result), visited, *result, array_length - 1);
	return *result;
  }

  int next_vertex(Array<int> & result) const {
	for (int i = 0; i < array_length; i++)
	  if (!result.contains(i))
		return i;
	return -1;
  }

  Array<int> & vertex_indexes(int start_vertex, bool * visited, Array<int> & result, int result_idx) {
	if (!visited[start_vertex]) {
	  visited[start_vertex] = true;
	  result.put(start_vertex);
	  for (int next_col = 0; next_col < array_length; next_col++)
		if (array[start_vertex][next_col] > 0 && !visited[next_col]) {
		  //result.put(next_col);
		  vertex_indexes(next_col, visited, result, result_idx);
		}
	}
	return result;
  }

 private:
  int **array;
  int array_length;
};


