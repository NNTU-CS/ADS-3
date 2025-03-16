// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max_value = num;
  while (num != 1) {
    if (num % 2 == 0) {
      num = num / 2;
    } else {
      num = 3 * num + 1;
    }
    if (num > max_value) {
      max_value = num;
    }
  }
  return max_value;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int counter = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num = num / 2;
    } else {
      num = 3 * num + 1;
    }
    counter++;
  }
  return counter;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int max_len_value = 0;
  unsigned int length = 1;
  *maxlen = 0;
  for (uint64_t i = lbound; i <= rbound; i++) {
    length = collatzLen(i);
    if (length > *maxlen) {
      *maxlen = length;
      max_len_value = i;
    }
  }
  return max_len_value;
}
