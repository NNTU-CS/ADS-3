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
  unsigned int length = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    ++length;
  }
  return length;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  uint64_t number = 0;
  *maxLen = 0;
  for (uint64_t i = lbound; i <= rbound; ++i) {
    unsigned int length = collatzLen(i);
    if (length > *maxLen) {
      *maxLen = length;
      number = i;
    }
  }
  return number;
}
