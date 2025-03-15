//Copyright [2025] <Copyright Alexey Efimov>
#include <cstdint>
#include <iostream>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t x = num;
while (num != 1) {
    if (num % 2 == 1) {
        num = 3 * num + 1;
        if (x <= num) {
            x = num;
        }
    }
    if (num % 2 == 0) {
        num = num / 2;
    }
}
return x;
}

unsigned int collatzLen(uint64_t num) {
  int len = 1;
while (num != 1) {
    if (num % 2 == 1) {
      num = 3 * num + 1;
    } else {
      num = num / 2;
    }
    len++;
}
return len;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  uint64_t num = 0;
unsigned int maxLen = 0;
for (uint64_t i = lbound; i <= rbound; i++) {
    if (static_cast<int>(collatzLen(i)) >= static_cast<int>(maxLen)) {
        maxLen = collatzLen(i);
        num = i;
    }
}
*maxlen = maxLen;
return num;
}
