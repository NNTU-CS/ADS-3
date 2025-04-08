// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t number) {
    uint64_t maximum = number;
    uint64_t current = number;

    while (true) {
        if (current == 1) break;

        if (current > maximum) maximum = current;

        if (current & 1) {
            current = 3 * current + 1;
        } else {
            current = current / 2;
        }
    }
    return maximum;
}

unsigned int collatzLen(uint64_t value) {
    unsigned int length = 0;
    uint64_t temp = value;

    do {
        length++;
        if (temp & 1) {
            temp = 3 * temp + 1;
        } else {
            temp = temp / 2;
        }
    } while (temp != 1);

    return length;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, uint64_t rbound) {
    unsigned int max_length = 0;
    uint64_t best_number = lbound;

    uint64_t current_num = lbound;
    while (current_num <= rbound) {
        uint64_t temp_value = current_num;
        unsigned int current_length = 1;

        while (temp_value != 1) {
            if (temp_value & 1) {
                temp_value = 3 * temp_value + 1;
            } else {
                temp_value = temp_value / 2;
            }
            current_length++;
        }

        if (current_length > max_length) {
            max_length = current_length;
            best_number = current_num;
        }
        current_num++;
    }

    *maxlen = max_length;
    return best_number;
}
