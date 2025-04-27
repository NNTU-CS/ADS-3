// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"
uint64_t collatzMaxValue(uint64_t n) {
 int64_t valu = 0;
  while (n != 1) {
    if (n > val) {
      val = n;
    }
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = 3 * n + 1;
    }
  }
  return val;
}
unsigned int collatzLen(uint64_t n) {
 int64_t k = 1;
  while (n != 1) {
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = 3 * n + 1;
    }
    k += 1;
  }
  return k;
}
unsigned int seqCollatz(unsigned int *maxlen,
                       uint64_t lbound,
                        uint64_t rbound) {
  int64_t n = 0, cunt = 0;
  for (int64_t i = lbound; i <= rbound; i++) {
    int64_t k = collatzLen(i);
    if (k > cunt) {
      cunt = k;
      n = i;
    }
  }
  *maxlen = cunt;
  return n;
}
