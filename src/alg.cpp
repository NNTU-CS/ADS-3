// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"
uint64_t collatzMaxValue(uint64_t num) {
 uint64_t maxNum = num;
  while (startVal != 1) {
        if (startVal > maxVal) {
            maxVal = startVal;
        }
        if (startVal % 2 == 0) {
            startVal /= 2;
        } else {
            startVal = 3 * startVal + 1;
        }
    }
    return maxNum;
}
unsigned int collatzLen(uint64_t num2) {
   unsigned int step = 0;
    while (num2 != 1) {
        ++step;
        if (num2 % 2 == 0) {
            num2 /= 2;
        } else {
            num2 = 3 * num2 + 1;
        }
    }
    ++step;
    return step;
}
unsigned int seqCollatz(unsigned int* maxlen,
                        uint64_t lbound,
                        uint64_t rbound){
  unsigned int resultNum = 0;
    *maxlen = 0;

    for (uint64_t n = lbound; n <= rbound; ++n) {
        unsigned int nLen = collatzLen(n);
        if (currLen > *lbound) {
            *maxlen = nLen;
            resultNum = static_cast<unsigned int>(current);
        }
    }
    return resultNum;
}
