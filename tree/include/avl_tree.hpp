//
// Created by yacopsae on 21/03/22.
//
#pragma once

#include "tree.hpp"

template<typename T>
class AvlTree : public Tree<T> {
 public:
  void insert(T) override;
  bool search(T) override;
  void remove(T) override;

 private:
  struct AvlNode {
	explicit AvlNode(T val) : _depth(0), _value(val) {}
	AvlNode(T val, int depth) : _depth(depth), _value(val) {}

   public:
	T &value();
	void value(T &);
	AvlNode *left();
	AvlNode *right();
	void left(AvlNode *);
	void right(AvlNode *);
	int depth();
	void depth(int);

   private:
	T _value;
	int _depth;
	AvlNode *_left;
	AvlNode *_right;
  };

  AvlNode *root;

 private:
  void insert(AvlNode *node, T x);
  bool small_left_rotation(AvlNode *, AvlNode *);
  bool small_right_rotation(AvlNode *, AvlNode *);
  void big_left_rotation(AvlNode *, AvlNode *);
  void big_right_rotation(AvlNode *, AvlNode *);
  void rebalance(AvlNode *, AvlNode *);
  int calc_height(AvlNode *node);

};

template<typename T>
void AvlTree<T>::insert(AvlNode *node, T x) {
  if (node->value() < x)
	if (node->right() != nullptr)
	  insert(node->right(), x);
	else
	  node->right(new AvlNode(x));
  else if (node->left() != nullptr)
	insert(node->left(), x);
  else
	node->left(new AvlNode(x));
}

template<typename T>
void AvlTree<T>::insert(T x) {
  if (root == nullptr)
	root = new AvlNode(x, 1);
  else if (search(x))
	return;
  else {
	insert(root, x);
	calc_height(root);
	rebalance(nullptr, root);
  }
}

template<typename T>
bool AvlTree<T>::search(T x) {
  return false;
}

template<typename T>
void AvlTree<T>::remove(T x) {

}

template<typename T>
bool AvlTree<T>::small_left_rotation(AvlNode *parent_node, AvlNode *node) {
  auto *right = node->right();
  auto *right_left = right->left();
  auto *right_right = right->right();

  if (right_right == nullptr || right_left == nullptr)
	return false;

  if (right_right->depth() < right_left->depth())
	return false;

  right->left(node);
  node->right(right_left);
  parent_node->left(right);
  return true;
}

template<typename T>
bool AvlTree<T>::small_right_rotation(AvlNode *parent_node, AvlNode *node) {
  auto *left = node->left();
  auto *left_left = left->left();
  auto *left_right = left->right();

  if (left_left == nullptr || left_right == nullptr)
	return false;

  if (left_left->depth() < left_right->depth())
	return false;

  left->right(node);
  node->left(left_right);

  if (parent_node != nullptr) {
	if (parent_node->left() != nullptr
		&& parent_node->left() == node)
	  parent_node->left(left);
	else
	  parent_node->right(left);
  } else {
	root = left;
  }

  return true;
}

template<typename T>
void AvlTree<T>::big_left_rotation(AvlNode *, AvlNode *) {

}

template<typename T>
void AvlTree<T>::big_right_rotation(AvlNode *, AvlNode *) {

}

template<typename T>
void AvlTree<T>::rebalance(AvlNode *node_parent, AvlNode *node) {
  if (node == nullptr ||
	  node->left() == nullptr ||
	  node->right() == nullptr) {
	return;
  }

  if (std::abs(node->left()->depth() - node->right()->depth()) < 2) {
	return;
  }

  rebalance(node, node->right());
  rebalance(node, node->left());

  if (node->left()->depth() >= node->right()->depth()) {
	if (!small_right_rotation(node_parent, node)) {
	  small_left_rotation(node, node->left());
	  small_right_rotation(node_parent, node);
	}
  }
  if (node->right()->depth() >= node->left()->depth()) {
	if (!small_left_rotation(node_parent, node)) {
	  small_right_rotation(node_parent, node);
	  small_left_rotation(node, node->right());
	}
  }
}

template<typename T>
int AvlTree<T>::calc_height(AvlNode *node) {
  if (node == nullptr)
	return 0;
  int left = calc_height(node->left());
  int right = calc_height(node->right());
  node->depth((left > right ? left : right) + 1);
  return node->depth();
}

template<typename T>
T &AvlTree<T>::AvlNode::value() {
  return _value;
}

template<typename T>
void AvlTree<T>::AvlNode::value(T &value) {
  _value = value;
}

template<typename T>
typename AvlTree<T>::AvlNode *AvlTree<T>::AvlNode::left() {
  return this->_left;
}

template<typename T>
typename AvlTree<T>::AvlNode *AvlTree<T>::AvlNode::right() {
  return this->_right;
}

template<typename T>
void AvlTree<T>::AvlNode::left(typename AvlTree<T>::AvlNode *node) {
  this->_left = node;
}

template<typename T>
void AvlTree<T>::AvlNode::right(typename AvlTree<T>::AvlNode *node) {
  this->_right = node;
}

template<typename T>
int AvlTree<T>::AvlNode::depth() {
  return this->_depth;
}

template<typename T>
void AvlTree<T>::AvlNode::depth(int depth) {
  this->_depth = depth;
}