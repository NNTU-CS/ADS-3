// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

unsigned int collatzLen(uint64_t num) {
  unsigned int kol = 0;
  for (uint64_t j = num; j != 1; ++kol) {
    if (j % 2 == 0) {
      j /= 2;
    } else {
      j = 3 * j + 1;
    }
  }
  return kol;
}

unsigned int seqCollatz(unsigned int* maxlen, uint64_t lbound, \
  uint64_t rbound) {
  *maxlen = 0;
  unsigned int num = 0;

  if (lbound == 0) {
    ++lbound;
  }

  for (uint64_t i = lbound; i <= rbound; ++i) {
    unsigned int len_seq = collatzLen(i);
    if (*maxlen <= len_seq) {
      *maxlen = len_seq;
      num = i;
    }
  }
  return num;
}

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max_value = num;
  for (uint64_t j = num; j != 1;) {
    if (j % 2 == 0) {
      j /= 2;
    } else {
      j = 3 * j + 1;
    }
    if (max_value < j) {
      max_value = j;
    }
  }
  return max_value;
}
