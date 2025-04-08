// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max= 0;
  while (num != 1) {
    if (num % 2 == 0) {
      num = num / 2;
    } else {
      num = num * 3;
      num++;
    }
    if (max < num) {
      max = num;
    }
  }
  return max;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int count = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num = num / 2;
    } else {
      num = num * 3;
      num++;
    }
    count++;
  }
  return count;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int max_d = lbound;
  uint64_t num;
  *maxlen = collatzLen(lbound);
  for (num = lbound + 1; num <= rbound; num++) {
    unsigned int cur_len = collatzLen(num);
    if (cur_len > *maxlen) {
      *maxlen = cur_len;
      max_d = num;
    }
  }
  return max_d;
}
