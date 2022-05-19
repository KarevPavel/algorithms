//
// Created by yacopsae on 05/05/2022.
//

#pragma once

#include "utils.hpp"
#include "tarjan.hpp"

class Kosaraju {

 public:
  Kosaraju(int **array, int array_length) : array(array), array_length(array_length) {}

  FactorArray<FactorArray<int> *> calc() {
	auto reverse_matrix = t_matrix();

	Tarjan tarjan(reverse_matrix, array_length);
	Utils::print_matrix(array, array_length);
	std::cout << "T MATRIX:\n";
	Utils::print_matrix(reverse_matrix, array_length);

	auto &list = tarjan.vertex_indexes();
	auto result = new FactorArray<FactorArray<int> * >(10);
	int result_index = 0;
	for (int i = 0; i < list.size(); i++)
	  if (reverse_matrix[list.get(i)][list.get(i + 1)] == 1) {
	    if (result->get(result_index) == nullptr) {
	      result->put(new FactorArray<int>());
	    }
		result->get(result_index)->put(list.get(i));
	  }
	  else
		result_index++;

	return *result;
  }

  int **t_matrix() {
	int **t_matrix = new int *[array_length];
	for (int col = 0; col < array_length; col++)
	  for (int row = 0; row < array_length; row++) {
		if (t_matrix[col] == nullptr)
		  t_matrix[col] = new int[array_length];
		t_matrix[col][row] = array[row][col];
	  }
	return t_matrix;
  }

 private:
  int **array;
  int array_length;

};