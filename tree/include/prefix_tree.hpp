//
// Created by yacopsae on 24/03/22.
//

#pragma once

#include "string"

template<typename V>
class PrefixTreeNode {
 public:
  explicit PrefixTreeNode(char key);
  PrefixTreeNode(char key, V *value);
  PrefixTreeNode *next_sibling();
  PrefixTreeNode<V> *next_sibling(PrefixTreeNode *);
  PrefixTreeNode *next_child();
  PrefixTreeNode<V> *next_child(PrefixTreeNode *);

  char key();
  V *value();
  void value(V *);

 private:
  PrefixTreeNode *_child;
  PrefixTreeNode *_sibling;

  char _key;
  V *_value;
};

template<typename V>
PrefixTreeNode<V>::PrefixTreeNode(char key): _key(key) {
}

template<typename V>
PrefixTreeNode<V>::PrefixTreeNode(char key, V *value): _key(key), _value(value) {
}

template<typename V>
char PrefixTreeNode<V>::key() {
  return _key;
}

template<typename V>
V *PrefixTreeNode<V>::value() {
  return _value;
}

template<typename V>
PrefixTreeNode<V> *PrefixTreeNode<V>::next_sibling() {
  return _sibling;
}
template<typename V>
PrefixTreeNode<V> *PrefixTreeNode<V>::next_sibling(PrefixTreeNode<V> *sibling) {
  this->_sibling = sibling;
  return sibling;
}
template<typename V>
PrefixTreeNode<V> *PrefixTreeNode<V>::next_child() {
  return this->_child;
}

template<typename V>
PrefixTreeNode<V> *PrefixTreeNode<V>::next_child(PrefixTreeNode<V> *child) {
  this->_child = child;
  return child;
}

template<typename V>
class PrefixTree {
 public:
  void del(const std::string&);
  void insert(const std::string &, V *);
  V *get(const std::string&);
  PrefixTreeNode<V> * find(const std::string& key);

 private:
  PrefixTreeNode<V> *root;

  PrefixTreeNode<V> *find_sibling(PrefixTreeNode<V> *, char);
  PrefixTreeNode<V> *find_child(PrefixTreeNode<V> *, char);
};

template<typename V>
void PrefixTree<V>::insert(const std::string &key, V *value) {
  if (key.length() < 1)
	throw std::runtime_error("Key cannot be empty!");

  if (root == nullptr) {
	root = new PrefixTreeNode<V>(key[0]);
	auto *node = root;
	for (int i = 1; i < key.length(); i++) {
	  if (i == key.length() - 1)
		node = node->next_child(new PrefixTreeNode<V>(key[i], value));
	  else
		node = node->next_child(new PrefixTreeNode<V>(key[i]));
	}
	return;
  }

  auto *node = find_sibling(root, key[0]);
  if (node == nullptr) {
	if (key.length() > 1)
	  node = root->next_sibling(new PrefixTreeNode<V>(key[0]));
	else {
	  root->next_sibling(new PrefixTreeNode<V>(key[0], value));
	  return;
	}
  }

  for (int i = 0; i < key.length(); i++) {
	if (node->key() == key[i]) {
	  if (node != nullptr && node->key() == key[i] && i == key.length() - 1) {
		node->value(value);
		return;
	  }
	  node = node->next_child();
	  continue;
	}
	if (!find_child(node, key[i])) {
	  if (i == key.length() - 1) {
		node->next_sibling(new PrefixTreeNode<V>(key[i], value));
		break;
	  } else
		node = node->next_sibling(new PrefixTreeNode<V>(key[i]));
	}
  }
}

template<typename V>
PrefixTreeNode<V> *PrefixTree<V>::find_sibling(PrefixTreeNode<V> *node, char k) {
  while (node != nullptr) {
	if (node->key() != k)
	  node = node->next_sibling();
	else
	  break;
  }
  return node;
}

template<typename V>
PrefixTreeNode<V> *PrefixTree<V>::find_child(PrefixTreeNode<V> *node, char k) {
  node = node->next_child();
  while (node != nullptr) {
	if (node->key() != k)
	  node = node->next_child();
	else
	  break;
  }
  return node;
}

template<typename V>
void PrefixTreeNode<V>::value(V *value) {
  this->_value = value;
}

template<typename V>
void PrefixTree<V>::del(const std::string& key) {
  auto * node = find(key);
  //Самое простое удаление, присваиваем значению null
  node->value(nullptr);
}

template<typename V>
V *PrefixTree<V>::get(const std::string& key) {
  auto * node = find(key);
  return node && node->value() != nullptr ? node->value() : nullptr;
}

template<typename V>
PrefixTreeNode<V> * PrefixTree<V>::find(const std::string& key) {
  if (key.length() < 1)
	throw std::runtime_error("Key cannot be empty!");

  auto *node = root;
  for (int i = 0; i < key.length(); i++) {
	node = find_sibling(node, key[i]);
	if (node == nullptr)
	  return nullptr;

	if (i == key.length() - 1 && node->key() == key[i])
	  return node;

	node = find_child(node, key[i]);
	if (node == nullptr)
	  return nullptr;
  }
  return nullptr;
}
