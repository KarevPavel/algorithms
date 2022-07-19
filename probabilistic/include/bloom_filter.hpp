//
// Created by yacopsae on 29/06/2022.
//

#pragma once

class BloomConditions {

};

class BloomFilter {

  BloomFilter(BloomConditions &bloom_condition) :
	  bloom_condition(bloom_condition) {}

 private:
  BloomConditions &bloom_condition;
};