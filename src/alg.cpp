// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t highpoint = num;
  while (num != 1) {
    if (num%2 ==0) {
      num = num/2;
    } else {
      num = 3*num +1;
    }
    if (num > highpoint) {
      highpoint = num;
    }
  }
  return highpoint;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int steps = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3*num +1;
    }
    ++steps;
  }
  return steps;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int longest = 0;
  unsigned int result = 0;

  for (uint64_t current = lbound; current <= rbound; ++current) {
    unsigned int length = collatzLen(current);
    if (length > longest) {
      longest = length;
      result = current;
    }
  }

  *maxlen = longest;
  return result;
}
