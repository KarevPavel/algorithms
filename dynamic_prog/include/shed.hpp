//
// Created by yacopsae on 02/06/2022.
//

#pragma once

#include "utils.hpp"
#include "iostream"
#include "istream"

static int colums, rows;
static int links = 0;
int calculate(bool **matrix, int column, int row) {
  if (column < 0 || column >= colums)
	return 0;
  if (row < 0 || row >= rows)
	return 0;
  if (matrix[column][row] == 1)
	return 0;

  matrix[column][row] = true;
  links += calculate(matrix, column + 1, row);
  links += calculate(matrix, column - 1, row);
  links += calculate(matrix, column, row + 1);
  links += calculate(matrix, column, row - 1);
  return links;
}

struct Entry {
  int left_value; //Значение указывает на кол-во пустых ячеек СЛЕВА
  int top_value;  //Значение указывает на кол-во пустых ячеек СВЕРХУ

  friend std::ostream &operator<<(std::ostream &os, const Entry &entry) {
	os << "[L:" << entry.left_value << ",T:" << entry.top_value << "]";
	return os;
  }
};

int shed_square_v2(std::istream &cin) {
  colums = 0, rows = 0;
  cin >> colums;
  cin >> rows;

  auto **matrix = new Entry *[colums]{nullptr};
  for (int row = 0; row < rows; row++) {
	for (int col = 0; col < colums; col++) {
	  bool b;
	  cin >> b;
	  if (matrix[col] == nullptr)
		matrix[col] = new Entry[rows];
	  if (!b) {
		int left_val = 1;
		int top_val = 1;
		int previous_col = col - 1;
		int previous_row = row - 1;
		if (previous_col > -1 && matrix[previous_col][row].left_value > 0)
		  left_val = matrix[previous_col][row].left_value + 1;
		if (previous_row > -1 && matrix[col][previous_row].top_value > 0)
		  top_val = matrix[col][previous_row].top_value + 1;
		matrix[col][row] = {left_val, top_val};
	  } else
		matrix[col][row] = {0, 0};
	}
  }

  Utils::print_2d_array(matrix, colums, rows);
}

/*int shed_square(std::istream &cin) {
  colums = 0, rows = 0;
  cin >> colums;
  cin >> rows;
  bool **matrix = new bool *[colums]{nullptr};
  for (int row = 0; row < rows; row++)
	for (int col = 0; col < colums; col++) {
	  bool b;
	  cin >> b;
	  if (matrix[col] == nullptr)
		matrix[col] = new bool[rows];
	  matrix[col][row] = b;
	}
  std::cout << calculate(matrix, 0, 0);
  return 0;
}*/
