// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t max = 0;
    while (num > 1) {
        if (num > max) {
            max = num;
        }
        if (num % 2 == 0) {
            num /= 2;
        } else{
            num = 3 * num + 1;
        }
    }
    return max;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int col = 1;
    while (num > 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        col++;
    }
    return col;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, uint64_t rbound) {
    *maxlen = 0;
    unsigned int maxCol = 0;
    uint64_t resultNum = lbound;
    for (uint64_t i = lbound; i <= rbound; i++) {
        uint64_t num = i;
        unsigned int col = 1;
        while (num > 1) {
            if (num % 2 == 0) {
                num /= 2;
            } else {
                num = 3 * num + 1;
            }
            col++;
        }
        if (col > maxCol) {
            maxCol = col;
            resultNum = i;
        }
    }
    *maxlen = maxCol;
    return resultNum;
}
