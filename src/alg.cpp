// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxVal = num;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    }
    else {
      num = 3 * num + 1;
    }
    if (num > maxVal) {
      maxVal = num;
    }
  }

  return maxVal;
}

unsigned int collatzLen(uint64_t num) {
  uint64_t len = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    }
    else {
      num = 3 * num + 1;
    }
    len++;
  }

  return len;
}

unsigned int seqCollatz(unsigned int* maxlen,
  uint64_t lbound,
  uint64_t rbound) {
  uint64_t maxLen = 0;
  uint64_t resultNum = 0;
  uint64_t highestNumInSequence = 0;
  for (uint64_t i = lbound; i <= rbound; ++i) {
    uint64_t currentLen = collatzLen(i);
    uint64_t currentMaxValue = collatzMaxValue(i);
    if (currentLen > maxLen) {
      maxLen = currentLen;
      resultNum = i;
      highestNumInSequence = currentMaxValue;
    }
  }
  *maxlen = maxLen;
  return resultNum;
}
