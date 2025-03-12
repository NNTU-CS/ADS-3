// Copyright 2025 NNTU-CS
#include "../include/alg.h"
#include <cstdint>

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max = num;
  while (num != 1) {
    if (num % 2 == 0)
      num /= 2;
    else
      num = 3 * num + 1;
    if (num > max)
      max = num;
  }
  return max;
}

unsigned int collatzLen(uint64_t num) {
  uint64_t len = 1;
  while (num != 1) {
    if (num % 2 == 0)
      num /= 2;
    else
      num = 3 * num + 1;
    len++;
  }
  return len;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound,
                        uint64_t rbound) {
  uint64_t max = 0;
  uint64_t len = 0;
  for (uint64_t i = lbound; i <= rbound; i++) {
    uint64_t l = collatzLen(i);
    if (l > len) {
      len = l;
      max = i;
    }
  }
  *maxlen = len;
  return max;
}
