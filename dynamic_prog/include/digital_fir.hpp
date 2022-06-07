//
// Created by yacopsae on 02/06/2022.
//

#pragma once

#include "iostream"
#include "string"

int fir(std::istream & cin) {
  bool is_first_digit = true;
  int **array;
  int max_col_in_row = 1;
  int current_col = 0;
  int current_row = 0;
  int tree_length = 0;
  int number;
  while (cin >> number) {
	if (is_first_digit) {
	  is_first_digit = false;
	  array = new int *[number];
	  for (int i = 0; i < number; i++)
		array[i] = new int[number];
	  tree_length = number;
	} else {
	  if (current_col >= max_col_in_row) {
		current_col = 0;
		max_col_in_row++;
		current_row++;
	  }
	  array[current_col++][current_row] = number;
	}
  }

  for (int row = tree_length - 1; row > 0; row--) {
	for (int col = 0; col < tree_length - 1; col++) {
	  array[col][row - 1] = array[col][row - 1] + std::max(array[col][row], array[col + 1][row]);
	}
  }
  return array[0][0];
}