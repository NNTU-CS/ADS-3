// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
        uint64_t result = num;
        while (num != 1) {
                if (num % 2 == 0) num = num / 2;
                else num = 3 * num + 1;
                if (num > result) result = num;
        }
        return result;
}

unsigned int collatzLen(uint64_t num) {
        unsigned int lenght = 1;
        while (num != 1) {
                if (num % 2 == 0) num = num / 2;
                else num = 3 * num + 1;
                lenght++;
        }
        return lenght;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
        unsigned int maxLenght = 1;
        unsigned int numberMaxLenght = lbound;
        for (uint64_t i = lbound; i <= rbound; i++) {
                unsigned int currentLenght = collatzLen(i);
                if (currentLenght > maxLenght) {
                        maxLenght = currentLenght;
                        numberMaxLenght = i;
                }
        }
        *maxlen = maxLenght;
        return numberMaxLenght;
}
