//
// Created by yacopsae on 11/02/22.
//
#include <factor_array.hpp>
#include "utils.hpp"
#include "vector_array.hpp"
#include "single_array.hpp"

int main() {

  auto single = SingleArray<int>();
  Utils::multiple_inserts_exec_time("SingleArray Test", single);

  auto vector = VectorArray<int>(10);
  Utils::multiple_inserts_exec_time("VectorArray(10) Test", vector);

  auto vector1 = VectorArray<int>(100);
  Utils::multiple_inserts_exec_time("VectorArray(100) Test", vector1);

  auto vector2 = VectorArray<int>(200);
  Utils::multiple_inserts_exec_time("VectorArray(200) Test", vector2);

  auto factor = FactorArray<int>(2);
  Utils::multiple_inserts_exec_time("FactorArray(2) Test", factor);

}