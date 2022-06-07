//
// Created by yacopsae on 11/02/22.
//
#include "utils.hpp"
#include "fibonacci.hpp"

int main() {
  Utils::print_exec_time_and_result("Recursive", &Fibonacci::recursive, 50ll);
  Utils::print_exec_time_and_result("Golden ratio", &Fibonacci::golden_ratio, 50ll);
  Utils::print_exec_time_and_result("Matrix", &Fibonacci::matrix, 50ll);
  Utils::print_exec_time_and_result("Iterative", &Fibonacci::iterative, 50ll);
}