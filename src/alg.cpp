// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max_val = 0;
  while (num != 1) {
    if (num % 2 == 1) {
      num = num * 3 + 1;
      max_val = (max_val > num ? max_val : num);
    }
    else {
      num /= 2;
    }
  }
  return max_val;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int len = 1;
  while (num != 1) {
    len++;
    if (num % 2 == 1) {
      num = num * 3 + 1;
    }
    else {
      num /= 2;
    }
  }
  return len;
}

unsigned int seqCollatz(unsigned int *maxlen,
uint64_t lbound,
uint64_t rbound) {
  uint64_t numb = 0;
  *maxlen = 2;
  for (int x = lbound; x <= rbound; x++) {
    unsigned int len = collatzLen(x);
    if (len > *maxlen) {
      *maxlen = len;
      numb = x;
    }
  }
  return numb;
}
