//
// Created by yacopsae on 13/05/2022.
//

#pragma once

#include <factor_array.hpp>
#include "vector_array.hpp"
#include <iostream>
#include "bubble_sort.hpp"

class Edge {
 public:
  Edge(int v1, int v2, int weight) : v1(v1), v2(v2), weight(weight) {}
 public:
  int v1;
  int v2;
  int weight;

  bool operator<(const Edge &rhs) const {
	return weight < rhs.weight;
  }

  bool operator>(const Edge &rhs) const {
	return weight > rhs.weight;
  }
};


class Kraskal {
 public:
  Kraskal(int **matrix, int array_length) :
	  matrix(matrix),
	  array_length(array_length),
	  parent(new int[array_length]){
	setup_parent();
  }

  void setup_parent() {
	for (int i = 0; i < array_length; i++)
	  parent[i] = i;
  }

  FactorArray<Edge *> skeleton() {
	auto factor_array = FactorArray<Edge *>(10);
	for (int i = 0; i < array_length; i++)
	  for (int j = 0; j < array_length; j++)
		if (j >= i && matrix[i][j] > 0)
		  factor_array.put(new Edge(i, j, matrix[i][j]));

	auto sort = new BubbleSort<Edge *>();
	factor_array.sort(sort);

	auto result = FactorArray<Edge *>(10);
	for (int i = 0; i < factor_array.size(); i++) {
	  Edge * edge = factor_array.get(i);
	  if (find_parent(edge->v1) != find_parent(edge->v2)) {
		merge(edge->v1, edge->v2);
		result.put(edge);
	  }
	}

	return result;
  }

 private:
  int find_parent(int vertex_id) {
	if (parent[vertex_id] == vertex_id)
	  return vertex_id;
	return parent[vertex_id] = find_parent(parent[vertex_id]);
  }

  void merge(int vertex_id0, int vertex_id1) {
    int parent0 = find_parent(vertex_id0);
    int parent1 = find_parent(vertex_id1);
    parent[parent0] = parent1;
  }

  int **matrix;
  int array_length;
  int * parent;
};