// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t edit_num(uint64_t num) {
  if (num % 2 == 0) {
    return num /= 2;
  }

  return num = num * 3 + 1;
}

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max_num = 1;
  while (num != 1) {
    if (num > max_num) {
      max_num = num;
    }

    num = edit_num(num);
  }

  return max_num;
}

unsigned int collatzLen(uint64_t num) {
  uint64_t length = 1;
  while (num != 1) {
    num = edit_num(num);
    length++;
  }

  return length;
}

unsigned int seqCollatz(unsigned int* maxlen,
  uint64_t lbound,
  uint64_t rbound) {
  uint64_t max_length = 0;
  uint64_t res_num = 0;
  for (uint64_t i = lbound; i <= rbound; ++i) {
    uint64_t length = collatzLen(i);
    if (length > max_length) {
      max_length = length;
      res_num = i;
    }
  }

  *maxlen = max_length;
  return res_num;
}
