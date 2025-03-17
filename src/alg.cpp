// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxValue = num;
  while (num != 1) {
    if (num % 2 != 0) {
      num = 3 * num + 1;
    } else {
      num /= 2;
    }
    if (num > maxValue) maxValue = num;
  }
  return maxValue;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int count = 1;
  while (num != 1) {
    count++;
    if (num % 2 != 0) {
      num = 3 * num + 1;
    } else {
      num /= 2;
    }
  }
  return count;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int num = 0;
  *maxlen = 1;
  for (unsigned int i = lbound; i <= rbound; i++) {
    unsigned int len = collatzLen(i);
    if (len > *maxlen) {
      *maxlen = len;
      num = i;
    }
  }
  return num;
}
