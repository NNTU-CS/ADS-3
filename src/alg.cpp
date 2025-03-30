// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maximum = num;
  while (num != 1) {
    if ((num % 2) == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    if (num > maximum) {
      maximum = num;
    }
  }
  return maximum;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int length = 1;
  while (num != 1) {
    if ((num % 2) == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    ++length;
  }
  return length;
}

unsigned int seqCollatz(unsigned int* maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int longest_len = 0;
  uint64_t best_num = 0;

  for (uint64_t current = lbound; current <= rbound; ++current) {
    unsigned int cur_len = collatzLen(current);
    if (cur_len > longest_len) {
      longest_len = cur_len;
      best_num = current;
    }
  }

  *maxlen = longest_len;
  return static_cast<unsigned int>(best_num);
}
