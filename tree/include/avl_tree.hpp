//
// Created by yacopsae on 21/03/22.
//
#pragma once

#include "tree.hpp"

template <typename T>
class AvlTree: public Tree<T> {
 public:
  void insert(T x) override;
  bool search(T x) override;
  void remove(T x) override;

 private:
  void small_left_rotation(Tree<T> t);
  void small_right_rotation(Tree<T> t);
  void big_left_rotation(Tree<T> t);
  void big_right_rotation(Tree<T> t);
  void rebalance(Tree<T> t);

  struct AvlNode : Tree<T>::Node {
	int depth;
  };
};

template <typename T>
void insert(T x) {

}

template <typename T>
bool search(T x) {

}

template <typename T>
void remove(T x) {

}

template <typename T>
void small_left_rotation(Tree<T> t) {

}

template <typename T>
void small_right_rotation(Tree<T> t) {

}

template <typename T>
void big_left_rotation(Tree<T> t) {

}

template <typename T>
void big_right_rotation(Tree<T> t) {

}

template <typename T>
void rebalance(Tree<T> t) {

}
