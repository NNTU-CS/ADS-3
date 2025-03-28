// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxValue = num;
  do {
    if (num % 2 != 0) {
      num = 3 * num + 1;
    } else {
      num /= 2;
    }
    if (num > maxValue) {
      maxValue = num;
    }
  } while (num != 1);
  return maxValue;
}

unsigned int collatzLen(uint64_t num) {
  uint64_t len = 1;
  do {
    if (num % 2 != 0) {
      num = 3 * num + 1;
    } else {
      num /= 2;
    }
    len++;
  } while (num != 1);
  return len;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  uint64_t maxLenSeq = 0, numMaxLenSeq = lbound;
  for (uint64_t num = lbound; num <= rbound; ++num) {
    uint64_t curLenSeq = 1;
    uint64_t curNum = num;
    do {
      if (curNum %2 == 0) {
        curNum /= 2;
      } else {
        curNum = 3 * curNum + 1;
      }
      curLenSeq++;
    } while (curNum != 1);
    if (curLenSeq > maxLenSeq) {
      maxLenSeq = curLenSeq;
      numMaxLenSeq = num;
    }
  }
  *maxlen = maxLenSeq;
  return numMaxLenSeq;
}
