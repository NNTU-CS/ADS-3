// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max = 0;
  while (num != 1) {
    if (num % 2 == 0)
      num /= 2;
    else
      num = num * 3 + 1;
    if (num > max)
      max = num;
  }
  return max;
}

unsigned int collatzLen(uint64_t num) {
  int len = 1;
  while (num != 1) {
    if (num % 2 == 0)
      num /= 2;
    else
      num = num * 3 + 1;
    len++;
  }
  return len;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  *maxlen = 0;
  int number;
  for (uint64_t i = lbound; i <= rbound; i++) {
    if (collatzLen(i) > *maxlen) {
      *maxlen = collatzLen(i);
      number = i;
    }
  }
  return number;
}
