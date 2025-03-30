// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  if (num == 0) {
    return 0;
  }
    uint64_t val = num;
    while (num != 1) {
        num = (num % 2 == 0) ? (num / 2) : (3 * num + 1);
        if (num > val) val = num;
    }
    return val;
}
unsigned int collatzLen(uint64_t num) {
  unsigned int length = 1;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        length++;
    }
    return length;
}
unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound,
uint64_t rbound) {
  if (lbound < 2) {
    lbound = 2;
  }
    if (rbound < lbound) {
        *maxlen = 0;
        return 0;
    }
    unsigned int max_length = 0;
    unsigned int result_num = 0;
    for (uint64_t n = lbound; n <= rbound; ++n) {
        unsigned int current_len = collatzLen(n);
        if (current_len > max_length) {
            max_length = current_len;
            result_num = static_cast<unsigned int>(n);
        }
    }
    *maxlen = max_length;
    return result_num;
}
