// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  return 1;
}

unsigned int collatzLen(uint64_t num) {
  return 1;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, uint64_t rbound) {
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
