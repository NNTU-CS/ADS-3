// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxVal = num;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    if (num > maxVal) {
      maxVal = num;
    }
  }
  return maxVal;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int len = 0;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    len++;
  }
  return len + 1;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int currentMaxLen = 0, numOfCurrentMaxLen = 0;
  for (uint64_t i = lbound; i <= rbound; i++) {
    unsigned int currentLen = collatzLen(i);
    if (currentLen > currentMaxLen) {
      currentMaxLen = currentLen;
      numOfCurrentMaxLen = i;
    }
  }
  *maxlen = currentMaxLen;
  return numOfCurrentMaxLen;
}
