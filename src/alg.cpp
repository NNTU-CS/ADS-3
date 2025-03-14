// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max = num;
  while (num > 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    if (num > max) {
      max = num;
    }
  }
  return max;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int length = 1;
  while (num > 1) {
    length++;
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
  }
  return length;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  uint64_t temp_num = 1;
  *maxlen = 1;
  for (uint64_t i = lbound; i <= rbound; i++) {
    unsigned int temp_len = collatzLen(i);
    if (temp_len > (*maxlen)) {
      temp_num = i;
      *maxlen = temp_len;
    }
  }
  return temp_num;
}
