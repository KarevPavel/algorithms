
#include <sstream>
#include <iostream>
#include "rle.hpp"
#include "rle_v2.hpp"

int main() {
  std::stringstream string_stream = std::stringstream {"ABABABABABABABA" };
  RLE(string_stream).compress(std::cout);
  std::cout << std::endl;
  std::stringstream string_stream2 = std::stringstream {"ABABABABABABABA" };
  RLEv2(string_stream2).compress(std::cout);
}