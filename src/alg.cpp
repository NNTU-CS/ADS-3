// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maximum = 0;
  while (num != 1) {
      if (num % 2 == 0) {
        num = num / 2;
      } else {
        num = num * 3 + 1;
      }
      if (maximum < num) {
        maximum = num;
      }
    }
  return maximum;
}

unsigned int collatzLen(uint64_t num) {
  uint64_t len = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = num * 3 + 1;
    }
    len += 1;
  }
  return len;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int maximum = 0;
  unsigned int startNum = 0;
  for (uint64_t i = lbound; i < rbound; i++) {
    if (collatzLen(i) > maximum) {
        maximum = collatzLen(i);
        startNum = i;
      }
    }
    *maxlen = maximum;
    return startNum;
}
