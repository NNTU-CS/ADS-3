// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxii = num;
    while (num != 1) {
       if (num % 2 != 0) {
        num = 3*num+1;
    } else {
        num = num/2;
    }
    if (num > maxii) {
        maxii = num;
    }
}
    return maxii;
}

unsigned int collatzLen(uint64_t num) {
  uint64_t count = 1;
    while (num != 1) {
        if (num % 2 != 0) {
            num = 3*num+1;
            count++;
        } else {
            num = num/2;
            count++;
        }
    }
    return count;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int number = 1;
    *maxlen = 1;
    for (uint64_t j = lbound; j <= rbound; j++) {
        unsigned int lengthh = collatzLen(j);
        if (lengthh > *maxlen) {
            *maxlen = lengthh;
            number = j;
        }
    }
    return number;
}
