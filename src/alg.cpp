// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num = num / 2;
      if (max < num)
        max = num;
    } else {
      num = 3 * num + 1;
      if (max < num)
        max = num;
    }
  }
  return max;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int res = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num = num / 2;
      ++res;
    } else {
      num = 3 * num + 1;
      ++res;
    }
  }
  return res;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int num = lbound;
  uint64_t len;
  uint64_t max_len = 1;
  for (int i = lbound; i <= rbound; ++i) {
    len = collatzLen(i);
    if (len > max_len) {
      num = i;
      *maxlen = len;
    }
  }
  return num;
}
