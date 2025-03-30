// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max = num;

  while (num != 1) {
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
  unsigned int len = 1;

  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    len++;
  }

  return len;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int max_len = 0;
  unsigned int res_num = 0;

  for (uint64_t i = lbound; i <= rbound; i++) {
    unsigned int current_len = collatzLen(i);
    if (current_len > max_len) {
      max_len = current_len;
      res_num = i;
    }
  }

  *maxlen = max_len;
  return res_num;
}
