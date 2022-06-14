//
// Created by yacopsae on 20/04/2022.
//

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/math/special_functions/pow.hpp>

using ull = unsigned long long;
using bfi = boost::multiprecision::int1024_t;

bfi collatz(const bfi& n) {
  std::cout << "\tN:" << n << std::endl;
  if (n == 1)
	return 1;
  else if (n % 2 == 0)
	return collatz(n / 2);
  else
	return collatz(3 * n + 1);
}

int main() {
  std::cout << sizeof(bfi) * 93571393692802302 << std::endl;
  std::cout << 93571393692802302 / std::numeric_limits<int>::max() << std::endl;

  /*bfi number = 93571393692802302;
  bfi result = collatz(number++);
  while(result == 1) {
    std::cout << "NUMBER:" << number + 1 << std::endl;
	result = collatz(number++);
  }
   */
}
