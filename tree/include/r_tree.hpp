//
// Created by yacopsae on 19/07/2022.
//

#pragma once

#include "tree.hpp"

double initial_seed = 0.600001;
int static pseudo_random() {
  return (initial_seed = 3.05 * initial_seed * (1 - initial_seed)) * 100000;
}

template<typename T>
struct RTreeNode {
  explicit RTreeNode(T v) : value(v), left(nullptr), right(nullptr), parent(nullptr) {}
  explicit RTreeNode(T v, RTreeNode * parent) : value(v), left(nullptr), right(nullptr), parent(parent) {}

  T value;
  RTreeNode *parent;
  RTreeNode *left;
  RTreeNode *right;
};

template<typename T>
class RandomTree : public Tree<T> {
 private:
  RTreeNode<T> *root;
  int length;

 public:
  void insert(T element) override {
	if (root == nullptr) {
	  root = new RTreeNode<T>(element);
	  return;
	}
	if (search(element))
	  return;
	auto *n = new RTreeNode<T>(element);
	insert(root, n);
	if ((pseudo_random()) % 2 == 0) {
	  move2Root(n);
	}
  }

  RTreeNode<T> *insert(RTreeNode<T> *node, RTreeNode<T> *new_node) {
	if (node->value < new_node->value) {
	  if (node->right != nullptr)
		insert(node->right, new_node);
	  else {
		node->right = new_node;
		new_node->parent = node;
	  }
	} else if (node->left != nullptr)
	  insert(node->left, new_node);
	else {
	  node->left = new_node;
	  new_node->parent = node;
	}
	return new_node;
  }

  void move2Root(RTreeNode<T> *node) {
	while (root != node) {
	  auto parent = node->parent;
	  if (parent->parent == nullptr) {
	    if (node->value < parent->value) {
	      if (node->right != nullptr)
		  	insert(node->right, parent);
	      else
	        node->right = parent;
		} else {
	      if (node->left != nullptr)
		  	insert(node->left, parent);
	      else
	        node->left = parent;
		}

	    if (parent->right == node)
	      parent->right = nullptr;
	    if (parent->left == node)
	      parent->left = nullptr;

		parent->parent = node;
		root = node;
		node->parent = nullptr;
		break;
	  }

	  if (node->parent->left == node) {
		right_rotation(node->parent, node);
	  }
	  else if (node->parent->right == node) {
		left_rotation(node->parent, node);
	  }
	}
  }

  void right_rotation(RTreeNode<T> *parent, RTreeNode<T> *node) {
	auto pp = parent->parent;
	if (node->right == nullptr) {
	  node->right = parent;
	  parent->parent = node;
	} else {
	  parent->left = nullptr;
	  parent->parent = nullptr;
	  insert(node->right, parent);
	}

	if (pp->left == parent) {
	  pp->left = node;
	} else
	  pp->right = node;

	node->parent = pp;
	parent->left = nullptr;
	parent->parent = node;
  }

  void left_rotation(RTreeNode<T> *parent, RTreeNode<T> *node) {
    auto pp = parent->parent;
    if (node->left == nullptr) {
	  node->left = parent;
	  parent->parent = node;
	} else {
      parent->right = nullptr;
      parent->parent = nullptr;
	  insert(node->left, parent);
	}

    if (pp->left == parent) {
      pp->left = node;
    } else
      pp->right = node;

	node->parent = pp;
	parent->right = nullptr;
	parent->parent = node;
  }

  RTreeNode<T> *find_node(RTreeNode<T> *node, T x) {
	if (node == nullptr)
	  return nullptr;

	if (node->value == x)
	  return node;

	if (node->value > x) {
	  return find_node(node->left, x);
	} else if (node->value < x)
	  return find_node(node->right, x);

	return nullptr;
  }

  bool search(T element) override {
	return find_node(root, element)!= nullptr;
  }

  void remove(T element) override {

  }
};

