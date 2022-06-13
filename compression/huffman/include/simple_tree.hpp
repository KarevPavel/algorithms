//
// Created by yacopsae on 09/06/2022.
//

#pragma once

#include <ostream>
template <typename T>
class Node {
 public:
  Node(): _value(nullptr), left(nullptr), right(nullptr) {};
  explicit Node(T * value):_value(value) {};

  bool operator==(const Node<T> &rhs) const {
	return *_value == *rhs._value;
  }

  bool operator!=(const Node &rhs) const {
	return rhs != *this;
  }

  friend std::ostream &operator<<(std::ostream &os, const Node node) {
	os << "_value: " << node._value << " left: " << node.left << " right: " << node.right;
	return os;
  }

  ~Node() {
	delete _value;
	delete right;
	delete left;
  }
  void r(Node * n) {
    this->right = n;
  }

  void l(Node * n) {
    this->left = n;
  }

  Node * r() {
	return this->right;
  }

  Node * l() {
	return this->left;
  }

  T * value() {
	return _value;
  }

 private:
  T * _value;
  Node * left;
  Node * right;
};