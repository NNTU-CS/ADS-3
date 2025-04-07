// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxnum = num;
  while (num != 1) {
    if (num > maxnum) maxnum = num;
    if (num % 2) {
      num = 3 * num + 1;
    } else {
      num /= 2;
    }
  }
  return maxnum;
}

unsigned int collatzLen(uint64_t num) {
  uint64_t len = 1;
  while (num != 1) {
    len++;
    if (num % 2) {
      num = 3 * num + 1;
    } else {
      num /= 2;
    }
  }
  return len;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int max_len = 0;
  unsigned int result = lbound;
  for (uint64_t num = lbound; num <= rbound; ++num) {
    unsigned int len = collatzLen(num);
    if (len > max_len) {
      max_len = len;
      result = num;
    }
  }
  *maxlen = max_len;
  return result;
}
