// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t max = 0;
    if (num == 1) {
        return 1;
    }
    for (uint64_t n = num; n !=1;) {
        if (max < n) {
                max = n;
            }
        if (n % 2 != 0) {
            n = 3 * n + 1;
        }
        else {
            n /= 2;
        }
    }
  return max;
}

unsigned int collatzLen(uint64_t num) {
    uint64_t len = 1;
    if (num == 1) {
        return 1;
    }
    for (uint64_t n = num; n !=1;) {
        if (n % 2 != 0) {
            len += 1;
            n = 3 * n + 1;
        }
        else {
            len += 1;
            n /= 2;
        }
    }
    return len;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
    uint64_t num = 0;
    unsigned int max = 0;
    for (uint64_t n = lbound; n <= rbound; n++){
        if (collatzLen(n) > max) {
            max = collatzLen(n);
            num = n;
        }
    }
    (*maxlen) = max;
    return num;
}
