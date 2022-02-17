//
// Created by yacopsae on 15/02/22.
//

#include "utils.hpp"
#include "number.hpp"

int main() {
  Utils::print_exec_time_and_result("O(N^2)", &PrimeNumber::EnumOfDivisors::prime_count, 10l);
  Utils::print_exec_time_and_result("O(N^2)", &PrimeNumber::EnumOfDivisors::prime_count, 100l);
  Utils::print_exec_time_and_result("O(N^2)", &PrimeNumber::EnumOfDivisors::prime_count, 1000l);
  Utils::print_exec_time_and_result("O(N^2)", &PrimeNumber::EnumOfDivisors::prime_count, 10000l);

  Utils::print_exec_time_and_result("O(N * Sqrt(N))", &PrimeNumber::Optimized::prime_count, 10l);
  Utils::print_exec_time_and_result("O(N * Sqrt(N))", &PrimeNumber::Optimized::prime_count, 100l);
  Utils::print_exec_time_and_result("O(N * Sqrt(N))", &PrimeNumber::Optimized::prime_count, 1000l);
  Utils::print_exec_time_and_result("O(N * Sqrt(N))", &PrimeNumber::Optimized::prime_count, 10000l);
  Utils::print_exec_time_and_result("O(N * Sqrt(N))", &PrimeNumber::Optimized::prime_count, 100000l);

  Utils::print_exec_time_and_result("O(N LN(N))", &PrimeNumber::PrimeCached::prime_count, 10l);
  Utils::print_exec_time_and_result("O(N LN(N))", &PrimeNumber::PrimeCached::prime_count, 100l);
  Utils::print_exec_time_and_result("O(N LN(N))", &PrimeNumber::PrimeCached::prime_count, 1000l);
  Utils::print_exec_time_and_result("O(N LN(N))", &PrimeNumber::PrimeCached::prime_count, 10000l);
  Utils::print_exec_time_and_result("O(N LN(N))", &PrimeNumber::PrimeCached::prime_count, 100000l);

}
