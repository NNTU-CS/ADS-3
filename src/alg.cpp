// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

unsigned int collatzLen(uint64_t num) {
    if (num == 0) return 0;

    unsigned int length = 1;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            if (num > (UINT64_MAX - 1) / 3) return UINT_MAX;
            num = 3 * num + 1;
        }
        length++;
    }
    return length;
}

uint64_t collatzMaxValue(uint64_t num) {
    if (num == 0) return 0;

    uint64_t maxValue = num;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            if (num > (UINT64_MAX - 1) / 3) return UINT64_MAX;
            num = 3 * num + 1;
            maxValue = std::max(maxValue, num);
        }
    }
    return maxValue;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, uint64_t rbound) {
    if (lbound > rbound || lbound == 0) {
        *maxlen = 0;
        return 0;
    }

    unsigned int maxLength = 0;
    uint64_t bestNum = 0;

    for (uint64_t num = lbound; num <= rbound; ++num) {
        unsigned int currentLength = collatzLen(num);

        if (currentLength > maxLength) {
            maxLength = currentLength;
            bestNum = num;
        }
    }

    *maxlen = maxLength;
    return static_cast<unsigned int>(bestNum);
}
