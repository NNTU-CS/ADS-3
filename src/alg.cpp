// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxValue = num;
  while (num != 1) {
    if (num % 2 == 0) {
      num = num / 2;
    } else {
      num = num * 3 + 1;
    }
    if (num > maxValue) {
      maxValue = num;
    }
  }
  return maxValue;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int lenght = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num = num / 2;
    } else {
      num = num * 3 + 1;
    }
    lenght++;
  }
  return lenght;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int maxLenght = 0;
  unsigned int numMaxLenght = lbound;
  for (uint64_t i = lbound; i <= rbound; i++) {
    unsigned int lenght = collatzLen(i);
    if (lenght > maxLenght) {
      maxLenght = lenght;
      numMaxLenght = i;
    }
  }
  *maxlen = maxLength;
  return numMaxLenght;
}
