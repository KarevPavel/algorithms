#include "table_generator.hpp"
#include <chrono>
template<typename Functor>
double execution_time(Functor functor);

int main() {
  double ns = execution_time(
	  []() {
		auto tbl = new TableGenerator{10};
		tbl->generate_table();
		tbl->print_table();
	  }
  );
  std::cout << "execution time: " << ns << " ns" << std::endl;
}

template<typename Functor>
double execution_time(Functor functor) {
  auto start = std::chrono::steady_clock::now();
  auto end = std::chrono::steady_clock::now();
  functor();
  auto diff = end - start;
  return std::chrono::duration<double, std::nano>(diff).count();
}
