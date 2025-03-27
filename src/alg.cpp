// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max = 0;
  while (num != 1) {
    if (num % 2 == 0) {
      num = num / 2;
    }
    else {
      num = 3 * num + 1;
    }
    if (max < num) {
      max = num;
    }
  }
  return max;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int count = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num = num / 2;
    }
    else {
      num = 3 * num + 1;
    }
    count += 1;
  }
  return count;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, uint64_t rbound) {
  unsigned int max_dig = lbound;
  *maxlen = collatzLen(lbound);
  for (uint64_t num = lbound + 1; num <= rbound; num++) {
    unsigned int current_len = collatzLen(num);
    if (current_len > *maxlen) {
      *maxlen = current_len;
      max_dig = num;
    }
  }
  return max_dig;
}
