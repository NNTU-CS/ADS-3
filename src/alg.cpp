// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maximum = num;
  while (num > 1) {
    if (num % 2 == 0) {
      num = num / 2;
    }
    if (num % 2 == 1) {
      num = 3 * num + 1;
    }
    if (num > maximum) {
      maximum = num;
    }
  }
  return maximum;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int result = 1;
  while (num > 1) {
    if (num % 2 == 0) {
      num = num / 2;
    }
    if (num % 2 == 1) {
      num = 3 * num + 1;
    }
    result++;
  }
  return result;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int maxlength = 0;
  uint64_t number = lbound;
  for (uint64_t qwe = lbound; qwe <= rbound; qwe++) {
    unsigned int qwelength = collatzLen(qwe);
    if (qwelength > maxlength) {
      maxlength = qwelength;
      number = qwe;
    }
  }
  *maxlen = maxlength;
  return number;
}
