// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t max = num;
    while (num != 1) {
        num = (num % 2 == 0) ? num / 2 : (num > (UINT64_MAX-1)/3 ? (printf("Overflow: %lu\n",num), exit(1), 0) : 3*num + 1);
        if (num > max) max = num;
    }
    return max;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int len = 1;
    while (num != 1) {
        num = (num % 2 == 0) ? num / 2 : (num > (UINT64_MAX-1)/3 ? (printf("Overflow: %lu\n",num), exit(1), 0) : 3*num + 1);
        len++;
        if (len > 1000000) { printf("Sequence too long\n"); exit(1); }
    }
    return len;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, uint64_t rbound) {
    unsigned int best_len = collatzLen(lbound);
    uint64_t best_num = lbound;
    
    for (uint64_t num = lbound+1; num <= rbound; num++) {
        unsigned int current = collatzLen(num);
        if (current > best_len) {
            best_len = current;
            best_num = num;
        }
    }
    
    *maxlen = best_len;
    return best_num;
}
