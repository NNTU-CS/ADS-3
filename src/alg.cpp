// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t startNumber) {
    uint64_t maxValue = startNumber;
    uint64_t currentNumber = startNumber; // Introduce a working copy
    while (currentNumber != 1) {
        if (currentNumber % 2 == 0) {
            currentNumber /= 2;
        } else {
            currentNumber = 3 * currentNumber + 1;
        }
        if (currentNumber > maxValue) {
            maxValue = currentNumber;
        }
    }
    return maxValue;
}

unsigned int collatzLen(uint64_t startNumber) {
    unsigned int sequenceLength = 1;
    uint64_t currentNumber = startNumber; //Introduce a working copy

    while (currentNumber != 1) {
        if (currentNumber % 2 == 0) {
            currentNumber /= 2;
        } else {
            currentNumber = 3 * currentNumber + 1;
        }
        sequenceLength++;
    }
    return sequenceLength;
}

unsigned int seqCollatz(unsigned int *maxSequenceLength,
    uint64_t lowerBound,
    uint64_t upperBound) {
    unsigned int maxLength = 1;
    unsigned int numberAtMaxLength = lowerBound;

    for (uint64_t i = lowerBound; i <= upperBound; ++i) {
        unsigned int currentLength = collatzLen(i);
        if (currentLength > maxLength) {
            maxLength = currentLength;
            numberAtMaxLength = i;
        }
    }

    *maxSequenceLength = maxLength; //Use descriptive name

    return numberAtMaxLength;
}
