// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxValue = num;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    if (num > maxValue) {
      maxValue = num;
    }
  }
  return maxValue;
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

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, uint64_t rbond) {
  unsigned int maxLength = 0;
  unsigned int result = 0;
  for (uint64_t i = lbound; i <= rbond; ++i) {
    unsigned int len = collatzLen(i);
    if (len > maxLength) {
      maxLength = len;
      result = static_cast<unsigned int>(i);
    }
  }
  *maxlen = maxLength;
  return result;
}
