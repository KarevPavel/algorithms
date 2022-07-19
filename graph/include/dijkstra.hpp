//
// Created by yacopsae on 19/07/2022.
//

#pragma once

#include <climits>
#include "edge.hpp"
#include "factor_array.hpp"
#include "limits"

class Dijkstra {

 public:
  Dijkstra(int **array, int array_length) :
	  matrix(array),
	  array_length(array_length) {
  }

  void min_path(int src) {
	int distance[array_length];
	bool processedV[array_length];

	for (int k = 0; k < 6; k++) {
	  distance[k] = INT_MAX;
	  processedV[k] = false;
	}

	distance[src] = 0;

	for (int k = 0; k < 6; k++) {
	  int m = min_dist(distance, processedV);
	  processedV[m] = true;
	  for (int k = 0; k < 6; k++) {
		if (!processedV[k] && matrix[m][k] && distance[m] != INT_MAX && distance[m] + matrix[m][k] < distance[k])
		  distance[k] = distance[m] + matrix[m][k];
	  }
	}

	std::cout << "Vertex\t\tDist" << std::endl;
	for (int k = 0; k < 6; k++) {
	  std::cout << k << "\t\t\t" << distance[k] << std::endl;
	}
  }

  static int min_dist(const int distance[], const bool Tset[]) {
	int minimum = INT_MAX, ind;
	for (int k = 0; k < 6; k++) {
	  if (!Tset[k] && distance[k] <= minimum) {
		minimum = distance[k];
		ind = k;
	  }
	}
	return ind;
  }

 private:
  int **matrix;
  int array_length;
};