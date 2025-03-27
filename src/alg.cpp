// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxVal = num;
  while (num != 1) {
    num = (num % 2 == 0) ? num / 2 : 3 * num + 1;
    if (num > maxVal)
      maxVal = num;
  }
  return maxVal;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int lenght = 1;
  while (num != 1) {
    num = (num % 2 == 0) ? num / 2 : 3 * num + 1;
    ++lenght;
  }
  return lenght;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int maxNumber = 0;
  *maxlen = 0;
  for (uint64_t i = lbound; i <= rbound; ++i) {
    unsigned int length = collatzLen(i);
    if (length > *maxlen) {
      *maxlen = length;
      maxNumber = i;
    }
  }
  return maxNumber;
}
