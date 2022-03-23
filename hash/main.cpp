//
// Created by yacopsae on 23/03/22.
//

#include <string>
#include "hash_table.hpp"

int main() {
  HashTable<std::string, int> test;
  test.put("TEST1", 1);
  test.put("TEST2", 1);
  test.put("TEST3", 1);
  test.put("TEST4", 1);
  std::cout << " TEST1 " << test.get("TEST1").value() << std::endl;

  return 0;
}