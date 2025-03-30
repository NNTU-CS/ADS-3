// Copyright 2025 NNTU-CS
#include <stdio.h>

#include <iostream>
#include <cstdint>

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max = num;
    while (num != 1) {
      if (num % 2 == 0) {
        num /= 2;
      }
      else {
        num = 3 * num + 1;
      }
      if (num > max) {
        max = num;
      }
   }
  return max;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int l = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    }
    else {
      num = 3 * num + 1;
    }
    l++;
  }
  return l;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  uint64_t nmaxl = 0;
  unsigned int maxl = 0;
  for (uint64_t num = lbound; num <= rbound; num++) {
    uint64_t n = num;
    unsigned int l = 1;
    while (n != 1) {
      if (n % 2 == 0) {
        n /= 2;
      }
      else {
        n = 3 * n + 1;
      }
      l++;
    }
      if (l > maxl) {
        maxl = l;
        nmaxl = num;
      }
  }
  *maxlen = maxl;
  return nmaxl;
}
