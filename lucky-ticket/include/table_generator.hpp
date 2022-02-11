//
// Created by yacopsae on 08/02/22.
//

#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>

class TableGenerator {

 public:
  explicit TableGenerator(int digit_count);
  ~TableGenerator();

 public:
  void generate_table();
  void print_table();
  void print_table(std::ostream& ostream);
  long long result();
 private:
  const int digit_count;
  const int rowCount;
  long long **table;

  void calc_lucky_count();
  void fill_zero();
  void one_digit_rule_table();
  void create_other_rules();
  void each_column_sum(int digits_counter);
};

