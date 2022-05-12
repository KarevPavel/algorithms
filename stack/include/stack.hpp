//
// Created by yacopsae on 10/05/2022.
//

#pragma once

template <typename T, int size>
class Stack {
 public:
  Stack(): array(new T[size]), top(0) {}
  ~Stack() {
	delete array;
  }

  bool push(T & element) {
    if (top > 0)
		array[top--] = element;
    else
	  return false;
  }

  T * pop() {
	if (top > 0)
	  return array[top--];
	return nullptr;
  }

  bool empty() {
	return top == 0;
  }

 private:
  T * array;
  int top;

};