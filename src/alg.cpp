// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxNum = num, helpNum = num;
  while (helpNum != 1) {
    if (helpNum % 2 == 0) {
      helpNum /= 2;
    } else {
      helpNum = helpNum * 3 + 1;
    }
    if (helpNum > maxNum) {
      maxNum = helpNum;
    }
  }
  return maxNum;
}

unsigned int collatzLen(uint64_t num) {
  uint64_t count = 1;
  uint64_t helpNum = num;
  while (helpNum != 1) {
    if (helpNum % 2 == 0) {
      helpNum /= 2;
    } else {
      helpNum = helpNum * 3 + 1;
    }
    count++;
  }
  return count;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  uint64_t maxLengthRow = 2;
  uint64_t maxNum = 2;
  for (uint64_t i = lbound; i <= rbound; i++) {
    uint64_t lengthRow = collatzLen(i);
    if (lengthRow > maxLengthRow) {
      maxLengthRow = lengthRow;
      maxNum = i;
    }
  }
  *maxlen = maxLengthRow;
  return maxNum;
}
