
#include <iostream>
#include <huffman.hpp>
#include "rle.hpp"

int main() {
  std::cout << "SOURCE: 1A2D" << std::endl;
  std::stringstream string_stream = std::stringstream {"1A2D" };
  std::ostringstream ostringstream;
  //RLE::compress(string_stream, ostringstream);
  RLE::compress(string_stream, std::cout);
  /*
  std::stringstream is = std::stringstream { ostringstream.str() };
  std::cout << "RESULT: ";
  RLE::decompress(is, std::cout);
  */

  /*
  std::ifstream issource;
  issource.open("//home/yacopsae/Desktop/matrix_3.png");
  std::ofstream ofstream {"//home/yacopsae/Desktop/matrix_3.rle"};
  RLE::compress(issource, ofstream);

  std::ifstream issource2;
  issource2.open("//home/yacopsae/Desktop/matrix_3.rle");
  std::ofstream ofstream2 {"//home/yacopsae/Desktop/matrix_3_decompressed.png"};
  RLE::decompress(issource2, ofstream2);*/

  //std::cout << std::endl;
  /*std::stringstream string_stream2 = std::stringstream {"AABC" };
  RLEv2(string_stream2).compress(std::cout);*/
  //std::cout << std::endl;
  //std::stringstream string_stream3 = std::stringstream {"AAVCCZX" };
  //Huffman(string_stream3).compress(std::cout);
}