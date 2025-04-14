// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

unsigned int cache[1000001] = {0};

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
  if (num == 1) return 1;

  if (num <= 1000000 && cache[num] != 0) {
    return cache[num];
  }

  unsigned int steps;
  if (num % 2 == 0) {
    steps = 1 + collatzLen(num / 2);
  } else {
    steps = 1 + collatzLen(3 * num + 1);
  }

  if (num <= 1000000) {
    cache[num] = steps;
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
