// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxValue = num;
  while (num != 1) {
    if (num % 2 == 0) {
        num = num / 2;
    } else {
        num = 3 * num + 1;
    }
    if (maxValue < num) {
        maxValue = num;
    }
  }
  return maxValue;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int count = 1;
  while (num != 1) {
    if (num % 2 == 0) {
        num = num / 2;
    } else {
        num = 3 * num + 1;
    }
    count++;
  }
  return count;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int temp = 0;
  *maxlen = 0;
  for (uint64_t i = lbound; i <= rbound; i++) {
    unsigned int len = collatzLen(i);
    if (*maxlen < len) {
        *maxlen = len;
        temp = i;
    }
  }
  return temp;
}
