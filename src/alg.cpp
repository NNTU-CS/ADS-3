// Copyright 2025 NNTU-CS
#include <cstdint>

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t maxValue = num;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        if (num > maxValue) {
            maxValue = num;
        }
    }
    return maxValue;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int length = 1;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        length++;
    }
    return length;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, uint64_t rbound) {
    unsigned int maxLength = 0;
    uint64_t maxNum = lbound;
    for (uint64_t i = lbound; i <= rbound; ++i) {
        unsigned int length = collatzLen(i);
        uint64_t maxValue = collatzMaxValue(i);
        if (length > maxLength) {
            maxLength = length;
            maxNum = i;
        }
    }
    *maxlen = maxLength;
    return maxNum; 
}
