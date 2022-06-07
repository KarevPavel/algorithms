//
// Created by yacopsae on 02/06/2022.
//
#pragma once

#include "utils.hpp"

static int matrix_size;

void set_zeros(bool ** matrix, int row, int col) {
  if (row < 0 || row >= matrix_size)
	return;
  if (col < 0 || col >= matrix_size)
	return;
  if (matrix[col][row] == 0)
	return;
  matrix[col][row] = false;
  set_zeros(matrix, row, col + 1);
  set_zeros(matrix, row, col - 1);
  set_zeros(matrix, row + 1, col);
  set_zeros(matrix, row - 1, col);
}

int islands_count(std::istream & cin) {
  matrix_size = 0;
  cin >> matrix_size;
  bool **matrix = new bool *[matrix_size]{nullptr};
  for (int col = 0; col < matrix_size; col++)
	for (int row = 0; row < matrix_size; row++) {
	  bool b;
	  cin >> b;
	  if (matrix[col] == nullptr)
		matrix[col] = new bool[matrix_size];
	  matrix[col][row] = b;
	}
  int islands_count = 0;
  for (int col = 0; col < matrix_size; col++)
	for (int row = 0; row < matrix_size; row++)
	  if (matrix[col][row] == 1) {
		islands_count++;
		set_zeros(matrix, row, col);

	  }
  return islands_count;
}