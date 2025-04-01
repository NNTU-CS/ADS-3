// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t current = num;
  uint64_t peak = current;

  while (current > 1) {
    current = (current % 2 == 0) ? (current / 2) : (current * 3 + 1);
    if (current > peak) {
      peak = current;
    }
  }

  return peak;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int steps = 1;
  uint64_t current = num;

  while (current > 1) {
    current = (current % 2 == 0) ? (current / 2) : (current * 3 + 1);
    ++steps;
  }

  return steps;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  *maxlen = 0;
  uint64_t best = 0;

  for (uint64_t n = lbound; n <= rbound; ++n) {
    unsigned int len = collatzLen(n);
    if (len > *maxlen) {
      *maxlen = len;
      best = n;
    }
  }

  return best;
}
