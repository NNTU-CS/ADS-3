// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

unsigned int collatzLen(uint64_t num) {
    unsigned int len = 0;
    if (num == 0) return 1;
    while (num > 0) {
        num /= 10;
        len++;
    }
    return len;
}

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

unsigned int seqCollatz(unsigned int* maxlen, uint64_t lbound, uint64_t rbound) {
    unsigned int num = 0;
    *maxlen = 0xFFFFFFFF;

    for (uint64_t i = lbound; i <= rbound; ++i) {
        unsigned int digitSum = static_cast<unsigned int>(collatzMaxValue(i));
        if (*maxlen > digitSum) {
            *maxlen = digitSum;
            num = static_cast<unsigned int>(i);
        }
    }

    return num;
}
