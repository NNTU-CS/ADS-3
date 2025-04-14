// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t startVal) {
    uint64_t maxVal = startVal;

    while (startVal != 1) {
        if (startVal > maxVal) {
            maxVal = startVal;
        }

        if (startVal % 2 == 0) {
            startVal /= 2;
        } else {
            startVal = 3 * startVal + 1;
        }
    }

    return maxVal;
}

unsigned int collatzLen(uint64_t initial) {
    unsigned int steps = 0;

    while (initial != 1) {
        ++steps;

        if (initial % 2 == 0) {
            initial /= 2;
        } else {
            initial = 3 * initial + 1;
        }
    }

    ++steps; // учитываем 1
    return steps;
}

unsigned int seqCollatz(
    unsigned int* longestLen,
    uint64_t rangeStart,
    uint64_t rangeEnd
) {
    unsigned int resultNum = 0;
    *longestLen = 0;

    for (uint64_t current = rangeStart; current <= rangeEnd; ++current) {
        unsigned int currLen = collatzLen(current);

        if (currLen > *longestLen) {
            *longestLen = currLen;
            resultNum = static_cast<unsigned int>(current);
        }
    }

    return resultNum;
}

