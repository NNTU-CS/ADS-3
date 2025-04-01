// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  unsigned int steps = 1;
  while (num != 1) {
    bool even = (num % 2 == 0);
    num = even ? num / 2 : num * 3 + 1;
    steps += 1;
  }
  return steps;
}

unsigned int collatzLen(uint64_t num) {
  uint64_t maxV = num;
  while (num != 1) {
    if (num % 2) {
      num = num * 3 + 1;
    } else {
      num = num / 2;
    }
    if (num > maxV) {
      maxV = num;
    }
  }
  return maxV;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  uint64_t resultNum = lbound;
  unsigned int maxLenFound = 0;

  for (uint64_t n = lbound; n <= rbound; ++n) {
    unsigned int len = collatzLen(n);
    if (len > maxLenFound) {
      maxLenFound = len;
      resultNum = n;
    }
  }

  if (maxlen != nullptr) {
    *maxlen = maxLenFound;
  }

  return resultNum;
}
