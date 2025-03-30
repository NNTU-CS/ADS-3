// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t max = num;
    while (num != 1) {
        if (num % 2 == 1) {
            num = 3 * num + 1;
        } else {
            num = num / 2;
        }
        if (num > max) {
            max = num;
        }
    }
    return max;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int len = 1;  // включаем само число
    while (num != 1) {
        if (num % 2 == 1) {
            num = 3 * num + 1;
        } else {
            num = num / 2;
        }
        len++;
    }
    return len;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
    unsigned int maxLength = 0;
    unsigned int resultNum = 0;
    for (uint64_t num = lbound; num <= rbound; ++num) {
        unsigned int currentLen = collatzLen(num);
        if (currentLen > maxLength) {
            maxLength = currentLen;
            resultNum = num;
        }
    }
    *maxlen = maxLength;
    return resultNum;
}
