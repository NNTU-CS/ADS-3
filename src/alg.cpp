// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxVal = num;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        if (num > maxVal) {
            maxVal = num;
        }
    }
    return maxVal;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int length = 0;
    while (num != 1) {
        length++;
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
    }
    return length + 1;
}

unsigned int seqCollatz(unsigned int* maxlen,
uint64_t lbound, uint64_t rbound) {
  int numbb = 0;
  *maxlen = 0;
  for (int i = lbound; i <= rbound; i++) {
    int var = collatzLen(i);
    if (var > *maxlen) {
      *maxlen = var;
      numbb = i;
    }
  }
  return num;
}
