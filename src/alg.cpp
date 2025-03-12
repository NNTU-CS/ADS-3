// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max = 0;
  while (num > 1) {
    if (num % 2 == 0) {
      if ((num / 2) > max)
      {
        max = num / 2;
        num = max;
      }
      else {
        num /= 2;
      }
    }
    else {
      if ((3 * num + 1) > max) {
        max = 3 * num + 1;
        num = max;
      }
      else {
        num = 3 * num + 1;
      }
    }
  }
  return max;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int len = 0;
  while (num > 1) {
    if (num % 2 == 0) num /= 2;
    else num = 3 * num + 1;
    len += 1;
  }
  return len + 1;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int max = 0;
  for (int i = lbound; i <= rbound; i++) {
    unsigned int tempLen = collatzLen(i);
    if (tempLen > *maxlen) {
      *maxlen = tempLen;
      max = i;
    }
  }
  return max;
}
