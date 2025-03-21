// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

std::unordered_map<uint64_t, unsigned int> collatz_cache;

unsigned int collatzLen(uint64_t num) {
  if (num == 1) return 1;
  if (collatz_cache.find(num) != collatz_cache.end()) {
    return collatz_cache[num];
  }
  unsigned int length = 1 + (num % 2 == 0 ? collatzLen(num / 2) : collatzLen(3 * num + 1));
  collatz_cache[num] = length;
  return length;
}

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max_val = num;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    if (num > max_val) {
      max_val = num;
    }
  }
  return max_val;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, uint64_t rbound) {
  unsigned int max_length = 0;
  unsigned int best_num = lbound;
  for (uint64_t num = lbound; num <= rbound; ++num) {
    unsigned int length = collatzLen(num);
    if (length > max_length) {
      max_length = length;
      best_num = num;
    }
  }
  *maxlen = max_length;
  return best_num;
}

