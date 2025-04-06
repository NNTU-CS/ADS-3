// Copyright 2025 NNTU-CS
#include "alg.h"
#include <cstdint>
#include <algorithm> 

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t maxValue = num;
    while (num != 1) {
        if (num & 1) {
            num = 3 * num + 1;
        } else {
            num /= 2;
        }
        maxValue = std::max(maxValue, num);
    } 
    return maxValue;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int length = 0;
    while (num != 1) {
        if (num & 1) { 
            num = 3 * num + 1;
        } else {
            num /= 2;
        }
        length++;
    }
    return length + 1; 
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, 
                         uint64_t rbound) {
    unsigned int maxLen = 0;
    uint64_t numWithMaxLen = lbound;

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
