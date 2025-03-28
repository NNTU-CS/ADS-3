// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
uint64_t max = num;
for (uint64_t i = num; i != 1;) {
if (i % 2 == 0) {
i /= 2;
} else {
i = 3 * i + 1;
}
if (i > max) max = i;
}
return max;
}

unsigned int collatzLen(uint64_t num) {
unsigned int lenght = 0;
while (num != 1) {
if (num % 2 == 0) {
num /= 2;
} else {
num = 3 * num + 1;
}
lenght++;
}
return lenght + 1;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
unsigned int maxlen_tmp = 0;
unsigned int num = 0;
for (uint64_t i = lbound; i <= rbound; i++) {
unsigned int current_len = collatzLen(i);
if (current_len > maxlen_tmp) {
maxlen_tmp = current_len;
num = i;
}
}
*maxlen = maxlen_tmp;
return num;
}
