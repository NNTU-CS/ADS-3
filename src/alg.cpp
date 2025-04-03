// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

unsigned int collatzLen(uint64_t num) {
  unsigned int length = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    length++;
  }
  return length;
}

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max_value = num;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    if (num > max_value) {
      max_value = num;
    }
  }
  return max_value;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, uint64_t rbound) {
  unsigned int max_num = lbound;
  *maxlen = collatzLen(lbound);
  for (uint64_t num = lbound + 1; num <= rbound; ++num) {
    unsigned int current_len = collatzLen(num);
    if (current_len > *maxlen) {
      *maxlen = current_len;
      max_num = num;
    }
  }
  return max_num;
}
