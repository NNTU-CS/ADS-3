// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max_value = 0;
  while (num != 1) {
    if (num % 2 == 1) {
      num = num * 3 + 1;
      max_value = (max_value > num ? max_value : num);
    }
    else {
      num /= 2;
    }
  }
  return max_value;
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

unsigned int seqCollatz(unsigned int* maxlen,
  uint64_t lbound,
  uint64_t rbound) {
  uint64_t number=0;
  for (int i = lbound; i <= rbound; i++) {
    unsigned int len = collatzLen(i);
    if (len > *maxlen || !maxlen) {
      *maxlen = len;
      number = i;
    }
  }
  return number;
}
