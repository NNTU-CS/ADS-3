// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max_value = 0;
  while (num > 1) {
    num = (num % 2 == 0) ? (num / 2) : (3 * num + 1);
    if (max_value < num) max_value = num;
  }
  return max_value;
}
unsigned int collatzLen(uint64_t num) {
  int i = 1;
  while (num > 1) {
    num = (num % 2 == 0) ? (num / 2) : (3 * num + 1);
    i++;
  }
  return i;
}
unsigned int seqCollatz(unsigned int* maxlen, uint64_t lbound, uint64_t rbound) {
  int num = 0, var = 0;
  *maxlen = 0;
  for (int i = lbound; i <= rbound; i++) {
    var = collatzLen(i);
    if (var > *maxlen) {
      *maxlen = var;
      num = i;
    }
  }
  return num;
}
