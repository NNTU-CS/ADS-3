// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, uint64_t rbound) {
unsigned int longestNum = 0;
*maxlen = 0;
for (uint64_t num = lbound; num <= rbound; ++num) {
unsigned int length = collatzLen(num);
if (length > *maxlen) {
*maxlen = length;
longestNum = num;
}
}
return longestNum;
}

unsigned int collatzLen(uint64_t num) {
unsigned int length = 1;
while (n != 1) {
if (n % 2 == 0) {
n = n / 2;
}
else {
n = 3 * n + 1;
}
length++;
}
return length;
}

uint64_t collatzMaxValue(uint64_t num) {
uint64_t max_value = num;
while (num != 1) {
if (num % 2 == 0) {
num /= 2;
}
else {
num = 3 * num + 1;
}
if (num > max_value) {
max_value = num;
}
}
return max_value;
}






