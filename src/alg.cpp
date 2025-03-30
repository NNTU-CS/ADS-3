// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t mx = num;
    while (num != 1) {
        if (num > mx) {
            mx = num;
        }
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
    }
    return mx;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int len = 0;
    while (num != 1) {
        len++;
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
    }

    len++;
    return len;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int numberWithMaxLen = 0;
    unsigned int currentLen = 0;
    *maxlen = 0;

    for (uint64_t num = lbound; num <= rbound; ++num) {
        currentLen = collatzLen(num);
        if (currentLen > *maxlen) {
            *maxlen = currentLen;
            numberWithMaxLen = static_cast<unsigned int>(num);
        }
    }
    return numberWithMaxLen;
}
