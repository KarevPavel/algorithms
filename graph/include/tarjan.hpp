//
// Created by yacopsae on 10/05/2022.
//

#pragma once

class Tarjan {

 public:
  Tarjan(int **array, int array_length) : array(array), array_length(array_length) {}

  int * vertex_indexes() {
	static auto visited = new bool[array_length];
	static auto result = new int [array_length];
	static int result_idx = array_length;
	return vertex_indexes(0, visited, result, result_idx);
  }

  int * vertex_indexes(int start_vertex, bool * visited, int * result, int result_idx) {
	if (!visited[start_vertex])
	  for (int next_col = 0; next_col < array_length; next_col++) {
		if (array[start_vertex][next_col] > 0)
		  result[result_idx--] = next_col;
		  vertex_indexes(next_col, visited, result, result_idx);
	  }
	return result;
  }

 private:
  int **array;
  int array_length;


};


