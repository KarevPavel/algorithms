//
// Created by yacopsae on 21/03/22.
//
#pragma

#include "tree.hpp"
#include "iostream"

template<typename T>
using Node = typename Tree<T>::Node;

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
	root = new Node<T>(x);
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
	  node->right(new Node<T>(x));
  else if (node->left() != nullptr)
	insert(node->left(), x);
  else
	node->left(new Node<T>(x));
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
