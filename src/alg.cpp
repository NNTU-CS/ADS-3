// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t maxValue = num;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        if (maxValue < num)
            maxValue = num;
    }
    return maxValue;
}

unsigned int collatzLen(uint64_t num) {
    uint64_t len = 0;
    if (num == 1) {
        len = 1;
        return len;
    }
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        len++;
    }
    return len;
}

unsigned int seqCollatz(unsigned int * maxlen, uint64_t lbound, uint64_t rbound) {
    uint64_t best_num = lbound;
    unsigned int max_len = collatzLen(lbound);
    for (uint64_t i = lbound + 1; i <= rbound; i++) {
        unsigned tempLen = collatzLen(i);
        if (max_len < tempLen) {
            max_len = tempLen;
            best_num = i;
        }
    }

    * maxlen = max_len;

    return best_num;
}
