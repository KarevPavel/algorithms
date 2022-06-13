
#include <iostream>
#include <string>
#include <huffman.hpp>

int main(int arg_count, char ** args) {

  //std::istringstream istringstream {"ABAAABCCCABBB"};
  std::ifstream file;
  file.open("/home/yacopsae/Desktop/2022-05-13_22-41.png");
  std::ofstream output {"/home/yacopsae/Desktop/2022-05-13_22-41.huffman"};
  Huffman::compress_v2(file, output);

  /*CountingPriorityQueue<char> pr_queue{};
  pr_queue.push('A');
  pr_queue.push('B');
  pr_queue.push('A');
  pr_queue.push('A');
  pr_queue.push('C');
  pr_queue.push('B');
  pr_queue.push('E');

  std::cout << "pr_queue.size: " << pr_queue.size() << std::endl;
  std::cout << "pop1: " << pr_queue.pop() << std::endl;
  std::cout << "pop2: " << pr_queue.pop() << std::endl;
  std::cout << "pop3: " << pr_queue.pop() << std::endl;*/
}