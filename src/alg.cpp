// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max = num;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num +1;
    }
    if (num > max) {
      max = num;
    }
  }
  return max;
}

uint64_t collatzLen(uint64_t num) {
  uint64_t len = 0;
  while (num != 1) {
    len++;
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
  }
  return len + 1;
}

uint64_t seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  uint64_t longnum = 0;
  *maxlen = 0;
  for (uint64_t i = lbound; i <= rbound; i++) {
    uint64_t len = collatzLen(i);
    if (len > *maxlen) {
      *maxlen = len;
      longnum = i;
    }
  }
  return longnum;
}
