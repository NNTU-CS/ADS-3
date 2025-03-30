// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max_s = num;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    if (num > max_s) {
      max_s = num;
    }
  }
  return max_s;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int len_s = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    len_s++;
  }
  return len_s;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int max_len = 0;
  uint64_t num_maxLen = 0;
  for (uint64_t i = ceiling; i <= floor; i++) {
    unsigned int lens = collatzLen(i);
    if (lens > max_len) {
      max_len = lens;
      num_maxLen = i;
      *maxlen = max_len;
    }
  }
  return num_maxLen;
}
