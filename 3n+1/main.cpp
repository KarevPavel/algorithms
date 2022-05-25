//
// Created by yacopsae on 20/04/2022.
//

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/math/special_functions/pow.hpp>

using ull = unsigned long long;
using bfi = boost::multiprecision::int1024_t;

int collatz(int n) {
  if (n == 1)
	return 1;
  else if (n % 2 == 0)
	return collatz(n / 2);
  else
	return collatz(3 * n + 1);
}

int main() {
  int number = 3;
  int result = number;
  while (collatz(number++) == 1);
}
