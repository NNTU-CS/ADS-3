// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <algorithm>


uint64_t collatzMaxValue(uint64_t num) {
    uint64_t maxValue = num;
    while (num != 1) {
        num = (num % 2 == 0) ? num / 2 : 3 * num + 1;
        maxValue = std::max(maxValue, num);
    }
    return maxValue;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int length = 1;
    while (num != 1) {
        num = (num % 2 == 0) ? num / 2 : 3 * num + 1;
        length++;
    }
    return length;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, uint64_t rbound) {
    unsigned int maxLen = 0;
    unsigned int numWithMaxLen = lbound;

    for (uint64_t i = lbound; i <= rbound; ++i) {
        unsigned int currentLen = collatzLen(i);
        if (currentLen > maxLen) {
            maxLen = currentLen;
            numWithMaxLen = i;
        }
    }

    *maxlen = maxLen;
    return numWithMaxLen;
}
