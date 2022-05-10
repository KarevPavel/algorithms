//
// Created by yacopsae on 05/05/2022.
//

#pragma once

#include "utils.hpp"
#include "tarjan.hpp"

class Kosaraju {

 public:
  Kosaraju(int **array, int array_length) : array(array), array_length(array_length) {}

  int ** calc() {
    auto reverse_matrix = t_matrix();
    Tarjan tarjan(array, array_length);
    Utils::print_array(tarjan.vertex_indexes(), array_length, std::cout);

  }

  void tarjan() {

  }

  int dfs(int vertex) {
    auto visited = new int [array_length];
    for (int child = 0; child < array_length; child++) {
	  if (!visited[child]) {
	    visited[child] = true;
	    dfs(child);
	  }
    }
  }

  int ** t_matrix() {
    int ** t_matrix = new int*[array_length];
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