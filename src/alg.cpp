// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxValue = 0;
  while (num != 1) {
    if (num % 2 == 0) {
      num = num / 2;   
    } else {
      num = num * 3 + 1;
    }
    if (num > maxValue) {
      maxValue = num
    }
  }
  return maxValue;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int lenght = 0;
  while (num != 1) {
    if (num % 2 == 0) {
      num = num / 2;
    } else {
      num = num * 3 + 1;
    }
    lenght++;
  }
  return lenght + 1;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int maxLenght = 0;
  unsigned int numMaxLenght = lbound;
  uint64_t maxNumMaxSeq = 0;
  for (uint64_t i = lbound; i <= rbound; i++) {
    unsigned int length = collatzLen(i);
    uint64_t maxValue = collatzMaxValue(i);
    if (lenght > maxLenght) {
      maxLenght = lenght;
      numMaxLenght = i;
      maxNumMaxSeq = maxValue;
    }
  }
  *maxlen = MaxLenght;
  return numMaxLenght;
}

