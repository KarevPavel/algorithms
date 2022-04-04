//
// Created by yacopsae on 21/03/22.
//
#pragma once

#include "tree.hpp"
#include "iostream"

template<typename T>
using Node = typename Tree<T>::Node;

template<typename T>
struct BSTreeNode : public Node<T> {
 public:
  explicit BSTreeNode(T value);
  ~BSTreeNode();
  T &value();
  Node<T> *left();
  Node<T> *right();

  void value(T &value);
  void left(Node<T> *node);
  void right(Node<T> *node);

 protected:
  T _value;
  Node<T> *_left;
  Node<T> *_right;
};


template <typename T>
BSTreeNode<T>::BSTreeNode(T value): _value(value) {}

template <typename T>
BSTreeNode<T>::~BSTreeNode() {
  _left = nullptr;
  _right = nullptr;
  delete _left;
  delete _right;
}
template <typename T>
T & BSTreeNode<T>::value() {
  return this->_value;
}

template <typename T>
typename Tree<T>::Node * BSTreeNode<T>::left() {
  return this->_left;
}

template <typename T>
typename Tree<T>::Node * BSTreeNode<T>::right() {
  return this->_right;
}

template <typename T>
void BSTreeNode<T>::value(T & value) {
  this->_value = value;
}

template <typename T>
void BSTreeNode<T>::left(Node<T> * node) {
  this->_left = node;
}

template <typename T>
void BSTreeNode<T>::right(Node<T> * node) {
  this->_right = node;
}


template<typename T>
class BSTree : public Tree<T> {
 public:
  BSTree() = default;
  ~BSTree() = default;
  void insert(T x) override;
  bool search(T x) override;
  void remove(T x) override;

 private:
  Node<T> *root;
  Node<T> *search_recursive(Node<T> *node, T x);
  Node<T> *find_min(Node<T> *parent);
  void insert(Node<T> *node, T x);
  Node<T> *remove(T x, Node<T> *t);
};

template<typename T>
bool BSTree<T>::search(T x) {
  if (this->root == nullptr)
	return false;
  auto *node = this->search_recursive(root, x);
  if (node == nullptr)
	return false;

  return node->value() == x;
}

template<typename T>
Node<T> *BSTree<T>::remove(T x, Node<T> *t) {
  Node<T> *temp;
  if (t == nullptr)
	return t;

  else if (x < t->value())
	t->left(remove(x, t->left()));
  else if (x > t->value())
	t->right(remove(x, t->right()));
  else if (t->left() && t->right()) {
	temp = find_min(t->right());
	t->value(temp->value());
	t->right(remove(t->value(), t->right()));
  } else {
	temp = t;
	if (t->left() == nullptr)
	  t = t->right();
	else if (t->right() == nullptr)
	  t = t->left();
	delete temp;
  }
  return t;
}

template<typename T>
void BSTree<T>::remove(T x) {
  remove(x, root);
}

template<typename T>
inline void BSTree<T>::insert(T x) {
  if (root == nullptr)
	root = new BSTreeNode<T>(x);
  else if (search(x))
	return;
  else
	insert(root, x);
}

template<typename T>
void BSTree<T>::insert(Node<T> *node, T x) {
  if (node->value() < x)
	if (node->right() != nullptr)
	  insert(node->right(), x);
	else
	  node->right(new BSTreeNode<T>(x));
  else if (node->left() != nullptr)
	insert(node->left(), x);
  else
	node->left(new BSTreeNode<T>(x));
}

template<typename T>
inline Node<T> *BSTree<T>::search_recursive(Node<T> *node, T x) {
  if (node == nullptr || node->value() == x)
	return node;
  if (node->value() < x)
	return search_recursive(node->right(), x);
  return search_recursive(node->left(), x);
}

template<typename T>
inline Node<T> *BSTree<T>::find_min(Node<T> *parent) {
  if (parent == nullptr)
	return parent;
  if (parent->left() == nullptr)
	return parent;
  return find_min(parent->left());
}
