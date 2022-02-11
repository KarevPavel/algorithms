//
// Created by yacopsae on 08/02/22.
//

#include "table_generator.hpp"

TableGenerator::TableGenerator(int digit_count) :
	digit_count(digit_count),
	rowCount(digit_count * 10 + 1),
	table(new long long *[rowCount]) {}

TableGenerator::~TableGenerator() {
  for (int i = 0; i < rowCount; i++) {
	delete[] table[i];
  }
  delete[] table;
}

void TableGenerator::generate_table() {
  fill_zero();
  one_digit_rule_table();
  each_column_sum(1);
  create_other_rules();
  calc_lucky_count();
}

long long TableGenerator::result() {
  return table[rowCount-1][rowCount-1];
}

void TableGenerator::create_other_rules() {
  for (int digits_counter = 2; digits_counter <= digit_count; digits_counter++) {
	int previousRowIndex = (digits_counter - 1) * 10;
	int previousMaxSum = (digits_counter - 1) * 10;
	for (int row = 1; row < 10; row++)
	  for (int sumColumn = 1; sumColumn <= previousMaxSum; sumColumn++) {
		table[previousRowIndex + row][sumColumn + row - 1] = table[previousRowIndex][sumColumn - 1];
	  }
	each_column_sum(digits_counter);
  }
}

void TableGenerator::each_column_sum(int digits_counter) {
  int rMax = 10 * digits_counter;
  for (int r = (digits_counter - 1) * 10; r < rMax; r++) {
	int cMax = 10 * digits_counter + 1;
	for (int c = 0; c < cMax; c++)
	  table[10 * digits_counter][c] += table[r][c];
  }
}

void TableGenerator::print_table(std::ostream &ostream) {
  ostream << std::setfill(' ') << std::setw(1) << "  ";
  for (int r = 0; r <= rowCount; r++) {
	ostream << std::setfill(' ') << std::setw(10) << r << " ";
  }

  ostream << std::endl;
  for (int r = 0; r < rowCount; r++) {
	ostream << "row #" << std::setfill(' ') << std::setw(6) << r << ": ";
	for (int c = 0; c < rowCount; c++) {
	  ostream << std::setfill(' ') << std::setw(10) << table[r][c] << " ";
	}
	ostream << std::endl;
  }
  ostream << std::endl;
  ostream << std::endl;
}

void TableGenerator::print_table() {
  print_table(std::cout);
}

void TableGenerator::calc_lucky_count() {
  long long rowSum = 0;
  for (int r = 1; r <= rowCount / 10; r++) {
	for (int c = 0; c < rowCount; c++) {
	  rowSum += pow(table[r * 10][c], 2L);
	}
	table[r * 10][rowCount - 1] = rowSum;
	rowSum = 0;
  }
}

void TableGenerator::fill_zero() {
  for (int row = 0; row < rowCount; ++row) {
	table[row] = new long long[rowCount];
	for (int sumColumn = 0; sumColumn < rowCount; sumColumn++)
	  table[row][sumColumn] = 0;
  }
}

void TableGenerator::one_digit_rule_table() {
  for (int number = 0; number < 10; number++) {
	for (int sum = 0; sum < 10; sum++) {
	  if (number == sum) {
		table[number][sum] = 1;
	  } else {
		table[number][sum] = 0;
	  }
	}
  }
}
