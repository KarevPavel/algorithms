//
// Created by yacopsae on 21/03/22.
//

#pragma


template <typename T>
class Tree {
 public:
  virtual void insert(T x) = 0;
  virtual bool search(T x) = 0;
  virtual void remove(T x) = 0;

  struct Node {
   public:
	explicit Node(T value);
	~Node();
	T & value();
	Node * left();
	Node * right();

	void value(T & value);
	void left(Node * node);
	void right(Node * node);

   protected:
	T _value;
	Node * _left;
	Node * _right;
  };

};

template <typename T>
Tree<T>::Node::Node(T value): _value(value) {}

template <typename T>
Tree<T>::Node::~Node() {
  _left = nullptr;
  _right = nullptr;
  delete _left;
  delete _right;
}
template <typename T>
T & Tree<T>::Node::value() {
  return this->_value;
}

template <typename T>
typename Tree<T>::Node * Tree<T>::Node::left() {
  return this->_left;
}

template <typename T>
typename Tree<T>::Node * Tree<T>::Node::right() {
  return this->_right;
}

template <typename T>
void Tree<T>::Node::value(T & value) {
  this->_value = value;
}

template <typename T>
void Tree<T>::Node::left(Tree<T>::Node * node) {
  this->_left = node;
}

template <typename T>
void Tree<T>::Node::right(Tree<T>::Node * node) {
  this->_right = node;
}
