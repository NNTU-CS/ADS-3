// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxColl = num;
  while (num > 1) {
      if (num % 2 == 0) {
          num >>=1;
      } else {
          num = (3 * num + 1);
      }
      if (num > maxColl) {
          maxColl = num;
      }
  }
  return maxColl;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int lenColl = 1;
  while (num != 1) {
      if (num % 2 == 0) {
          num /= 2;
      } else {
          num = (3 * num + 1);
      }
      lenColl++;
  }
  return lenColl;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int Num = 0;
  *maxlen = 0;
  for (uint64_t n = lbound; n <= rbound; n++) {
      unsigned int len = collatzLen(n);
      if (len > *maxlen) {
          *maxlen = len;
          Num = n;
      }
  }
  return Num;
}
