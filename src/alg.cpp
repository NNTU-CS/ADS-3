// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t currentMax = num;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num - 1;
        }
        if (num > currentMax) {
            currentMax = num;
        }
    }
    return currentMax;
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
    return length + 1;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
    unsigned int maxSequenceLength = 0;
    unsigned int resultNumber = lbound;

    for (uint64_t i = lbound; i <= rbound; i++) {
        unsigned int currentLength = collatzLen(i);
        if (currentLength > maxSequenceLength) {
            maxSequenceLength = currentLength;
            resultNumber = i;
        }
    }

    *maxlen = maxSequenceLength;
    return resultNumber;
}
