// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxNumber = num;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    if (num > maxNumber) {
      maxNumber = num;
    }
  }
  return maxNumber;
}

unsigned int collatzLen(uint64_t num) {
  uint64_t lenght = 0;
  while (num != 1) {
    lenght++;
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
  }
  return lenght + 1;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int maxLenght = 0;
  unsigned int maxNum = 0;
  for (uint64_t num = lbound; num <= rbound; num++) {
    unsigned int result = collatzLen(num);
    if (result > maxLenght) {
      maxLenght = result;
      maxNum = num;
    }
  }
  *maxlen = maxLenght; // Исправлено на maxLenght
  return maxLenght;
}
