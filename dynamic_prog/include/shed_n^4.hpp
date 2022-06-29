//
// Created by yacopsae on 29/06/2022.
//

#pragma once
#include "iostream"

class Shed {
 public:
  Shed(bool **matrix, int column, int row) :
	  _matrix(matrix),
	  _column(column),
	  _row(row) {}

  int calculate();

 private:
  int square_at(int, int);
  int height_at(int, int);

 private:
  bool **_matrix;
  int const _column;
  int const _row;
};

static int shed_square(std::istream &cin) {
  int c = 0, r = 0;
  cin >> c;
  cin >> r;
  bool **matrix = new bool *[c]{nullptr};
  for (int row = 0; row < r; row++)
	for (int col = 0; col < c; col++) {
	  bool b;
	  cin >> b;
	  if (matrix[col] == nullptr)
		matrix[col] = new bool[r];
	  matrix[col][row] = b;
	}
  Utils::print_2d_array(matrix, c, r);
  return Shed(matrix, c, r).calculate();
}

int Shed::calculate() {
  int maxSquare = 0;
  for (int y = 0; y < _row; y++)
	for (int x = 0; x < _column; x++) {
	  int square = square_at(x, y);
	  if (maxSquare < square)
		maxSquare = square;
	}
  return maxSquare;
}

int Shed::square_at(int x, int y) {
  int maxSquare = 0, minHeight = _column;
  for (int width = 1; x + width - 1 < _column; width++) {
	int height = height_at(x + width - 1, y);
	if (minHeight > height)
	  minHeight = height;
	int square = width * minHeight;
	if (maxSquare < square)
	  maxSquare = square;
  }
  return maxSquare;
}

int Shed::height_at(int x, int y) {
  int height = 0;
  while (y >= height && !_matrix[x][y - height])
	height++;
  return height;
}