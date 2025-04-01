// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxim = num;
  while (num != 1) {
    if (num % 2) {
      num = 3 * num + 1;
    } else {
      num /= 2;
    }
    if (maxim < num) {
      maxim = num;
    }
  }
  return maxim;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int len = 0;
  while (num != 1) {
    if (num % 2) {
      num = 3 * num + 1;
    } else {
      num /= 2;
    }
    len++;
  }
  return len + 1;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  if (lbound > rbound) {
    *maxlen = 0;
    return 0;
  }
  unsigned int maxNum = 0;
  *maxlen = 0;
  for (uint64_t i = lbound; i <= rbound; i++) {
    unsigned int len = collatzLen(i);
    if (len > *maxlen) {
      *maxlen = len;
      maxNum = i;
    }
  }
  return maxNum;
}
