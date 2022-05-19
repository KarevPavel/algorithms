//
// Created by yacopsae on 13/05/2022.
//

#pragma once

#include <factor_array.hpp>
#include <iostream>
class Edge {
 public:
  Edge(int v1, int v2, int weight): v1(v1), v2(v2), weight(weight) {}
 public:
  int v1;
  int v2;
  int weight;
};

class Kraskal {
 public:
  Kraskal(int **matrix, int array_length) :
  matrix(matrix),
  array_length(array_length) {}

  Edge * skeleton() {
	auto factor_array = FactorArray<Edge *>();
	for (int i = 0; i < array_length; i++)
	  for (int j = 0; j < array_length; j++)
		if (j >= i && matrix[i][j] > 0)
		  factor_array.put(new Edge{i, j, matrix[i][j]});

	for (int i = 0; i < factor_array.size(); i++) {
		std::cout << "Edge [ " << (factor_array.get(i)->v1) << ", " << (factor_array.get(i)->v2) << ", w: " << (factor_array.get(i)->weight) << " ]" << std::endl;
	}

	return nullptr;
  }

 private:
  int **matrix;
  int array_length;
};