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
        length++;
    }
    return length;
}

unsigned int seqCollatz(unsigned int *maxlen,
    unsigned int max_length = 0;
    unsigned int result_num = lbound;
    
    for (uint64_t i = lbound; i <= rbound; ++i) {
        unsigned int current_length = collatzLen(i);
        if (current_length > max_length) {
            max_length = current_length;
            result_num = i;
        }
    }
    
    *maxlen = max_length;
    return result_num;
  return 1;
}
