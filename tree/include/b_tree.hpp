//
// Created by yacopsae on 29/03/22.
//

#pragma once
#include "tree.hpp"

template<unsigned int tuple_size, typename T>
class BTreeNode : public Tree<T>::Node {
 public:
  BTreeNode() {
	value_array = new T[tuple_size];
	reference_array = new BTreeNode[tuple_size + 1];
  }

  ~BTreeNode() {
	delete[] value_array;
  }

 public:
  bool insert_next();


 private:
  int *value_array;
  BTreeNode *reference_array;
};

template<unsigned int tuple_size, typename T>
class BTree : public Tree<T> {
 public:
  BTree() = default;
  ~BTree() = default;
  void insert(T) override;
  bool search(T) override;
  void remove(T) override;

 private:
  BTreeNode<tuple_size, T> *root;
};


template<unsigned int tuple_size, typename T>
void BTree<tuple_size, T>::insert(T value) {
	if (root == nullptr)
	  root = new BTreeNode<tuple_size, T>(value);
}

template<unsigned int tuple_size, typename T>
bool BTree<tuple_size, T>::search(T value) {

}


template<unsigned int tuple_size, typename T>
void BTree<tuple_size, T>::remove(T value) {

}