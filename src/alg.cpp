// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max_value = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num = num / 2;
    } else {
      num = 3 * num + 1;
    }
    if (num > max_value) {
      max_value = num;
    }
  }
  return max_value;
}

unsigned int collatzLen(uint64_t num) {
  uint64_t len = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num = num / 2;
    } else {
      num = 3 * num + 1;
    }
    len++;
  }
  return len;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  uint64_t numberOfmaxLen = 1;
  unsigned int maximumLen = 1;
  for (; lbound < rbound + 1; lbound++) {
    int m = collatzLen(lbound);
    if (m > maximumLen) {
      maximumLen = m;
      numberOfmaxLen = lbound;
    }
  }
  *maxlen = maximumLen;
  return numberOfmaxLen;
}
