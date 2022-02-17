#include "table_generator.hpp"
#include "../utils/include/utils.hpp"

int main() {
  double ns = Utils::execution_time_ns(
	  []() {
		auto tbl = new TableGenerator{11};
		tbl->generate_table();
		tbl->print_table();
		return tbl->result();
	  }
  );
  std::cout << "execution time: " << ns << " ns" << std::endl;
}
