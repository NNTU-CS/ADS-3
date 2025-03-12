// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max = num;
  if (num > max) {
    max = num;
  }
  if (num == 1) {
    return max;
  }
  if (num % 2 == 0) {
    return collatzMaxValue(num / 2);
  }
  return collatzMaxValue(3 * num + 1);
}

unsigned int collatzLen(uint64_t num) {
  unsigned int len = 0;
  if (num == 1) {
    return len;
  }
  if (num % 2 == 0) {
    ++len;
    return collatzMaxValue(num / 2);
  }
  ++len;
  return collatzMaxValue(3 * num + 1);
}

unsigned int seqCollatz(unsigned int* maxlen,
  uint64_t lbound,
  uint64_t rbound) {
  uint64_t num = 0;
  for (uint64_t i = lbound; i < rbound; ++i) {
    uint64_t len = collatzMaxValue(i);
    if (len > *maxlen) {
      *maxlen = len;
      num = i;
    }
  }
  return num;
}
