// Copyright 2025 NNTU-CS
#include <cstdint>

#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxnum = num;
  while (num != 1) {
    if (num % 2 != 0) {
      num = 3 * num + 1;
    } else {
      num = num / 2;
    }
    if (num > maxnum) {
      maxnum = num;
    }
  }
  return maxnum;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int len = 1;
  while (num != 1) {
    if (num % 2 != 0) {
      num = 3 * num + 1;
      len++;
    } else {
      num = num / 2;
      len++;
    }
  }
  return len;
}

unsigned int seqCollatz(unsigned int* maxlen, uint64_t lbound,
                        uint64_t rbound) {
  uint64_t best_number = 0;
  unsigned int best_length = 0;
  for (uint64_t i = lbound; i <= rbound; i++) {
    unsigned int current_length = collatzLen(i);
    if (current_length > best_length) {
      best_length = current_length;
      best_number = i;
    }
  }
  *maxlen = best_length;
  return best_number;
}
