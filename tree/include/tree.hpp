//
// Created by yacopsae on 21/03/22.
//

#pragma once

template<typename T>
class Tree {
 public:
  virtual void insert(T x) = 0;
  virtual bool search(T x) = 0;
  virtual void remove(T x) = 0;

  struct Node {
   public:
	virtual T &value() = 0;
	virtual Node *left() = 0;
	virtual Node *right() = 0;
	virtual void value(T &value) = 0;
	virtual void left(Node *node) = 0;
	virtual void right(Node *node) = 0;
  };
};
