// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max = num;
  uint64_t n = num;
  while (n != 1) {
      if (n % 2 == 1)
          n = 3 * n + 1;
      else
          n = n / 2;
      if (n > max)
          max = n;}
  return max;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int len = 1;
  uint64_t n = num;
  while (n != 1) {
      if (n % 2 == 1)
          n = 3 * n + 1;
      else
          n = n / 2;
      len += 1;}
return len;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  uint64_t index = lbound;
  *maxlen = 0;

  for (uint64_t i = lbound; i <= rbound; i++) {
      unsigned int current_len = collatzLen(i);
      if (current_len > *maxlen) {
          *maxlen = current_len;
          index = i;
      }
  }
  
  //uint64_t maxic = collatzMaxValue(index);
  //cout << "Max value in collatz: " << maxic << endl;
  return index;
}
