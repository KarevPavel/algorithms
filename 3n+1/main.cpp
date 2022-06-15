//
// Created by yacopsae on 20/04/2022.
//

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/math/special_functions/pow.hpp>
#include <chrono>

using bfi = boost::multiprecision::int1024_t;

bfi collatz(const bfi& n) {
  std::cout << n << ", ";
  if (n == 4)
	return 1;
  else if (!(n & 1))
	return collatz(n / 2);
  else
	return collatz(3 * n + 1);
}

int main() {
  bfi number = 93571393692802302;
  int calculated = 1;
  double sum_time_left = 0;
  auto start = std::chrono::steady_clock::now();
  do {
    std::cout << " ]" << std::endl;
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double, std::milli> fp_ms = end - start;
	sum_time_left += fp_ms.count();
	std::cout << "AVERAGE: " << (sum_time_left / calculated++) << " INIT NUMBER:" << number + 1 << " [";
	start = std::chrono::steady_clock::now();
  } while (collatz(number++) == 1);


  std::cout << "EXIT LOOP ON NUMBER:" << number - 1 << std::endl;
}