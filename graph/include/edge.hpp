//
// Created by yacopsae on 19/07/2022.
//

#pragma once


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
