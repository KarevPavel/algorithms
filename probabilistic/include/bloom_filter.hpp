//
// Created by yacopsae on 29/06/2022.
//

#pragma once

#include <functional>
#include <string>
#include <cmath>
#include <stdexcept>

struct BloomFilterParams {
  BloomFilterParams(int element_count, double false_positive_probability) :
	  element_count(element_count),
	  false_positive_probability(false_positive_probability) {}
  const int element_count;
  const double false_positive_probability;
};

class BloomFilter {

 public:
  explicit BloomFilter(BloomFilterParams bloom_filter_params) {
	bitmap_size =
		std::ceil((bloom_filter_params.element_count * std::log(bloom_filter_params.false_positive_probability)
			/ std::log(1 / std::pow(2, std::log(2)))));
	bit_map = new bool[bitmap_size] { false };
	hash_func_count = std::round((bitmap_size / bloom_filter_params.element_count) * std::log(2));
	if (hash_func_count > 1)
	  throw std::runtime_error("Not implemented");
  }

  void add(const std::string &key) {
    //Тут на самом деле прогоняем по всем хеш-функциям и записываем в bit_map
	bit_map[std::hash<std::string>{}(key) & bitmap_size] = true;
  }

  bool contains(std::string key) {
    //Так же вычисляем все хешфункции, по индексам кажлой хешфункции достаём результат и если хоть один бит == 0, возвращаем false;
	return
		bit_map[std::hash<std::string>{}(key) & bitmap_size];
  }

 private:
  unsigned int hash_func_count;
  unsigned long bitmap_size;
  bool *bit_map;
};