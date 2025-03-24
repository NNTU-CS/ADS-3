// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxValue = num;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
            if (num > maxValue) {
                maxValue = num;
            }
        }
    }
    return maxValue;
}
unsigned int collatzLen(uint64_t num) {
  unsigned int len = 1;
    while (num != 1){
      if (num % 2 == 0) {
          num /= 2;
      } else {
        num = num * 3 + 1;
      }
      len++;
    }
  return len;
}
unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int maxLength = 0;
    uint64_t numberWithMaxLength = lbound;

    for (uint64_t num = lbound; num <= rbound; num++) {
        unsigned int length = collatzLen(num);
        if (length > maxLength) {
            maxLength = length;
            numberWithMaxLength = num;
        }
    }

    *maxlen = maxLength;
    return numberWithMaxLength;
}
