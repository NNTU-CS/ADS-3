// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  int64_t a = 0;
  while (num != 1) {
    if (num > a) {
      a = num;
    }
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
  }
  return a;
}

unsigned int collatzLen(uint64_t num) {
  int64_t k = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
      k += 1;
    } else {
      num = 3 * num + 1;
      k += 1;
    }
  }
  return k;
}

unsigned int seqCollatz(unsigned int* maxlen, 
                        uint64_t lbound,
                        uint64_t rbound) {
  int64_t num = 0, cnt = 0;
  for (int64_t i = lbound; i <= rbound; i++) {
    int64_t k = collatzLen(i);
    if (k > cnt) {
      cnt = k;
      num = i;
    }
  }
  *maxlen = cnt;
  return num;
}
