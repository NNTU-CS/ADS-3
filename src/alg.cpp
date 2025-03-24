// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"


uint64_t collatzMaxValue(uint64_t num) {
  int max = num;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    }else {
      num = 3 * num + 1;
    }
    if (num > max) {
      max = num;
    }
  }
  return max;
}


unsigned int collatzLen(uint64_t num) {
  unsigned int dlin = 0;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    }else {
      num = 3 * num + 1;
    }
    dlin+=1;
  }
  return dlin+1;
}

unsigned int seqCollatz(unsigned int* maxlen,
  uint64_t lbound,
  uint64_t rbound) {
  unsigned int max = 0;
  unsigned int maxLen = 0;
  for (uint64_t i = lbound; i <= rbound; ++i) {
    unsigned int this_len = collatzLen(i);
    if (this_len > maxLen) {
      maxLen = this_len;
      max = i;
    }
  }
  *maxlen = maxLen;
  return max;
}
