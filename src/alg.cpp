// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxValue = num;
  uint64_t temp = num;
  while (temp != 1) {
    if (temp % 2 == 0)
      temp = temp / 2;
    else
      temp = 3 * temp + 1;
    if (temp > maxValue)
      maxValue = temp;
  }
  return maxValue;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int length = 1;
  uint64_t temp = num;
  while (temp != 1) {
    if (temp % 2 == 0)
      temp = temp / 2;
    else
      temp = 3 * temp + 1;
    length++;
  }
  return length;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int maxLen = 0;
  unsigned int nwithmaxlen = 0;
  for (uint64_t i = lbound; i <= rbound; i++) {
    unsigned int length = collatzLen(i);
    if (length > maxLen) {
      maxLen = length;
      nwithmaxlen = i;
    }
  }
  *maxlen = maxLen;
  return nwithmaxlen;
}
