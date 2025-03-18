// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

unsigned int collatzLen(uint64_t num) {
  unsigned int len = 0;
  while (num != 1) {
    if (num % 2 == 1)
      num = 3 * num + 1;
    else
      num /= 2;
    len++;
  }
  return ++len;
}

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max = num;
  while (num != 1) {
    if (num % 2 == 1)
      num = 3 * num + 1;
    else
      num /= 2;
    max = max > num ? max : num;
  }
  return max;
}

unsigned int seqCollatz(unsigned int* maxlen, uint64_t lbound,
                        uint64_t rbound) {
  unsigned int num = 0;
  *maxlen = 0;
  for (uint64_t i = lbound; i <= rbound; i++) {
    if (*maxlen < collatzLen(i)) {
      *maxlen = collatzLen(i);
      num = i;
    }
  }
  return num;
  }
