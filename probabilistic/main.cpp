//
// Created by yacopsae on 29/06/2022.
//
#include <iostream>
#include "bloom_filter.hpp"

int main() {
  std::srand (time (NULL));
  int test_elements_count = 400;
  std::string words[test_elements_count];
  for (int i = 0; i < test_elements_count; i++) {
	int word_length = rand() % 15 + 1;
	std::string word;
	for (int l = 0; l < word_length; l++) {
	  char letter = 65 + (rand() % 25);
	  word.push_back(letter);
	}
	words[i] = word;
  }

  BloomFilter bloom_filter(BloomFilterParams{
	  400, 0.5
  });

  for (int i = 0; i < test_elements_count; i++) {
	bloom_filter.add(words[i]);
  }

  int check_elements_count = 100;
  for (int i = 0; i < check_elements_count; i++) {
    std::string random_word = words[rand() % test_elements_count];
    bool isContains = bloom_filter.contains(random_word);
    std::cout << "Check word '" << random_word << "' contains: " << isContains << std::endl;
    if (!isContains)
      std::cout << std::endl << std::endl << "IMPOSSIBLE!!!" << std::endl << std::endl;
  }
}

