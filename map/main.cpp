//
// Created by yacopsae on 23/03/22.
//

#include <string>
#include "hash_table.hpp"
#include "hash.hpp"

int main() {
  HashTable<std::string, int> test = HashTable<std::string, int>(Hash::simple_hash);//Hash::simple_hash);
  test.put("TEST1", 1);
  test.put("TEST1", 444);
  test.put("TEST3", 5555);
  test.put("TEST4", 1);
  test.put("TEST6", 1);
  test.put("TEST7", 1);
  test.put("TEST8", 1);
  test.put("TEST9", 1);
  test.put("TEST10", 1);
  test.put("TEST11", 1);
  std::cout << " TEST1 " << test.get("TEST1")->value() << std::endl;
  test.remove("TEST1");
  std::cout << " TEST1 CONTAINS:" << test.contains("TEST1")<< std::endl;
  std::cout << " TEST11 CONTAINS:" << test.contains("TEST11")<< std::endl;

  return 0;
}