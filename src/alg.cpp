// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t resul = num;
  while (num != 1) {
        if (num % 2 != 0) {
            num = 3 * num + 1;
        } else {
            num = num / 2;
        }
        if (num > resul) {
        resul = num;
        }
    }
    return resul;
}

unsigned int collatzLen(uint64_t num) {
   unsigned int lenN = 1;
    while (num != 1) {
        if (num % 2 != 0) {
            num = 3 * num + 1;
        } else {
            num = num / 2;
        }
        lenN++;
    }
    return lenN;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {unsigned int max_len = 0;
    uint64_t num = lbound;
    for (uint64_t i = lbound; i <= rbound; ++i) {
        unsigned int lenN = collatzLen(i);
        if (lenN > max_len) {
            max_len = lenN;
            num = i;
        }
    }
    *maxlen = max_len;
    return num;
 
}

