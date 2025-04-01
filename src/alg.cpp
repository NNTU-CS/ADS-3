// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  unsigned int count = 0;
  while (num > 1) {
    if (num % 2 == 0) {
      num = num / 2;
    } else {
      num = num * 3 + 1;
    }
    count++;
  }
  return count;
}

unsigned int collatzLen(uint64_t num) {
  uint64_t maxV = num;
  while (num != 1) {
    if (num & 1) {
      num = num * 3 + 1;
    } else {
      num /= 2;
    }
    if (num > maxV)
      maxV = num;
  }
  return maxV;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  uint64_t best = lbound;
  *maxlen = 1;
  for (uint64_t val = lbound; val <= rbound; ++val) {
    unsigned int len = collatzLen(val);
    if (len > *maxlen) {
      *maxlen = len;
      best = val;
    }
  }
  return best;
}
