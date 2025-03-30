// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t max_val = num;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        if (num > max_val) {
            max_val = num;
        }
    }
    return max_val;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int length = 1;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        ++length;
    }
    return length;
}

unsigned int seqCollatz(
    unsigned int* max_len, uint64_t lbound, uint64_t rbound) {
    unsigned int best_num = 0;
    unsigned int best_len = 0;

    for (uint64_t i = lbound; i <= rbound; ++i) {
        unsigned int len = collatzLen(i);
        if (len > best_len) {
            best_len = len;
            best_num = i;
        }
    }

    *max_len = best_len;
    return best_num;
}
