// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  if (num == 0) {
    return 0;
  }
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
  if (num == 0) {
    return 0;
  }
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
  if (maxlen == nullptr || lbound == 0 || rbound == 0 || lbound > rbound) {
    if (maxlen) *maxlen = 0;
    return 0;
  }
  unsigned int maxLength = 0;
  unsigned int resultNum = lbound;
  for (uint64_t num = lbound; num <= rbound; ++num) {
    uint64_t current = num;
    unsigned int currentLength = 1;

    while (current != 1) {
      if (current % 2 == 0) {
        current /= 2;
      } else {
        current = 3 * current + 1;
      }
      ++currentLength;
    }
    if (currentLength > maxLength) {
      maxLength = currentLength;
      resultNum = num;
    }
  }
  *maxlen = maxLength;
  return static_cast<unsigned int>(resultNum);
}
