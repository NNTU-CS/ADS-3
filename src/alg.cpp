// Copyright 2025 NNTU-CS
#include <cstdint>
#include <iostream>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  int max = num;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } 
    else {
      num = 3 * num + 1;
    }
    if (num > max){
      max = num;
    }
  }
  return max;
}

unsigned int collatzLen(uint64_t num) {
  int count = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } 
    else {
      num = 3 * num + 1;
    }
    count++;
  }
  return count;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  *maxlen = 0;
  uint64_t longest_seq_num = 0;
  uint64_t max_val_in_longest_seq = 0;
  for (uint64_t i = lbound; i <= rbound; ++i) {
    unsigned int current_len = collatzLen(i);  
    if (current_len > *maxlen) {
      *maxlen = current_len;
      longest_seq_num = i;
      max_val_in_longest_seq = collatzMaxValue(i);
    }
  }
  return longest_seq_num;
}
