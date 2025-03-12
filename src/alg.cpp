// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max_val = num;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    }
    else {
      num = num * 3 + 1;
    }
    if (num > max_val) {
      max_val = num;
    }
  }
  return max_val;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int len = 0;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    }
    else {
      num = num * 3 + 1;
    }
    len++;
  }
  return len;
}

unsigned int seqCollatz(unsigned int* maxlen,
  uint64_t lbound,
  uint64_t rbound) {
  uint64_t num = 0;
  for (uint64_t i = lbound; i < rbound; ++i) {
    uint64_t len = collatzLen(i);
    if (len > *maxlen) {
      *maxlen = len;
      num = i;
    }
  }
  return num;
}
