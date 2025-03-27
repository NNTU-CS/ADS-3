// Copyright 2025 NNTU-CS
#include <cstdint>

#include "alg.h"

using namespace std;

unsigned int collatzLen(uint64_t num) {
  unsigned int len = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    len++;
  }
  return len;
}

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max_val = num;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    max_val = max(max_val, num);
  }
  return max_val;
}

unsigned int seqCollatz(unsigned int* maxlen, uint64_t lbound,
                        uint64_t rbound) {
  if (lbound > rbound) {
    *maxlen = 0;
    return 0;
  }

  unsigned int max_len = 0;
  unsigned int best_num = 0;

  for (uint64_t i = lbound; i <= rbound; ++i) {
    unsigned int current_len = collatzLen(i);
    if (current_len > max_len) {
      max_len = current_len;
      best_num = static_cast<unsigned int>(i);
    }
  }

  *maxlen = max_len;
  return best_num;
}
