// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t startVal) {
    uint64_t max = starT;

    while (starT != 1) {
        if (starT > max) {
            max = starT;
        }

        if (starT % 2 == 0) {
            starT /= 2;
        } else {
            starT = 3 * starT + 1;
        }
    }

    return max;
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

    for (uint64_t curent = rangeStart; curent <= rangeEnd; ++curent) {
        unsigned int curLen = collatzLen(curent);

        if (curLen > *longestLen) {
            *longestLen = curLen;
            resultNum = static_cast<unsigned int>(curent);
        }
    }

    return resultNum;
} 
