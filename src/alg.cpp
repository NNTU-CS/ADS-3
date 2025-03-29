// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    if (num == 0) return 0;
    uint64_t max_val = num;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            if (num > (UINT64_MAX - 1) / 3) {
                return UINT64_MAX;
            }
            num = 3 * num + 1;
        }
        if (num > max_val) {
            max_val = num;
        }
    }
    return max_val;
}

unsigned int collatzLen(uint64_t num) {
    if (num == 0) return 0;
    unsigned int length = 1;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            if (num > (UINT64_MAX - 1) / 3) {
                return 0;
            }
            num = 3 * num + 1;
        }
        length++;
    }
    return length;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
    if (lbound < 2) lbound = 2;
    if (rbound < lbound) return 0;
    unsigned int max_length = 0;
    unsigned int result_num = lbound;
    for (uint64_t i = lbound; i <= rbound; ++i) {
        unsigned int current_len = collatzLen(i);
        if (current_len == 0) continue;
        if (current_len > max_length) {
            max_length = current_len;
            result_num = i;
        }
    }
    if (maxlen) *maxlen = max_length;
    return result_num;
}
