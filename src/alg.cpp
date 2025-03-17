// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint32_t max = num;
  while (num > 1) {
    if (num % 2 == 0) {
      num /= 2;
    }
    else {
      num = num * 3 + 1;
    if (num > max) {
        max = num;
    }
    }
  }
  return max;
}

unsigned int collatzLen(uint64_t num) {
  uint32_t sum = 1;

  while (num > 1) {
    if (num % 2 == 0) {
      num /= 2;
      sum++;
    }
    else {
      num = num * 3 + 1;
      sum++;
    }
  }
  return sum;
}

unsigned int seqCollatz(unsigned int* maxlen,
  uint64_t lbound,
  uint64_t rbound) {
  uint32_t num = 0;
  *maxlen = 0;

  for (int i = lbound; i <= rbound; i++) {
    if (collatzLen(i) > *maxlen) {
      num = i;
      *maxlen = collatzLen(i);
    }
  }

  return num;
}
