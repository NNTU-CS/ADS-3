// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t n = num;
  uint16_t c = 1;
  while (n != 1) {
    if (n % 2 == 0) {
      n = n / 2;
      if (n > c) {
        c = n;
      }
    } else {
      n = 3 * n + 1;
      if (n > c) {
        c = n;
      }
    }
  }
  return c;
}

unsigned int collatzLen(uint64_t num) { 
  uint64_t n = num;
  uint16_t c = 1;
  while (n != 1) {
    if (n % 2 == 0) {
      n = n / 2;
      c += 1;
      }
      else {
      n = 3 * n + 1;
      c += 1;
    }
  }
  return c;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  uint64_t ch = 0;
  unsigned int m = 0;
  for (uint64_t i = lbound; i < rbound+1; i++) {
    if (collatzLen(i) > m) {
      ch = i;
      m = collatzLen(i);
    }
  }
  *maxlen = m;
  return ch;
}
