//
// Created by yacopsae on 11/02/22.
//

#include "cmath"
#include "utils.hpp"
#include <pow.hpp>

int main() {
  Utils::print_exec_time_and_result("Pow iterative", &Pow::iterative, 2, 20);
  Utils::print_exec_time_and_result<double>("Std::pow", &std::pow, 2, 20);
  Utils::print_exec_time_and_result<long double>("Std::pow", &Pow::throughMultiplication, 1.125, 128);
  Utils::print_exec_time_and_result<double>("Std::pow", &std::pow, 1.125, 128);
  Utils::print_exec_time_and_result<long long>("Std::pow", &Pow::throughMultiplication, 2, 100);
  Utils::print_exec_time_and_result<double>("Std::pow", &std::pow, 2, 100);
}