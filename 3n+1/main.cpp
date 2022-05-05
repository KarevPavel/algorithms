//
// Created by yacopsae on 20/04/2022.
//

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/math/special_functions/pow.hpp>

using ull = unsigned long long;
using bfi = boost::multiprecision::int1024_t;
int main() {
  std::cout << "test: " << boost::math::pow<68, bfi>(2) << std::endl;
}
