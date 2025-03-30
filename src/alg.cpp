// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define CACHE_SIZE 2000000
unsigned int *cache = NULL;

void initCache() {
    cache = (unsigned int*)calloc(CACHE_SIZE, sizeof(unsigned int));
    if (cache == NULL) {
        fprintf(stderr, "Ошибка выделения памяти для кэша\n");
        exit(1);
    }
    cache[1] = 1;
}

void freeCache() {
    free(cache);
}

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max_val = num;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    if (num > max_val) {
      max_val = num;
    }
  }
  return max_val;
}

unsigned int collatzLen(uint64_t num) {
  if (num < CACHE_SIZE && cache[num] != 0) {
    return cache[num];
  }
  unsigned int len;
  if (num % 2 == 0) {
    len = 1 + collatzLen(num / 2);
  } else {
    len = 1 + collatzLen(3 * num + 1);
  }
  if (num < CACHE_SIZE) {
    cache[num] = len;
  }
  return len;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, uint64_t rbound) {
  uint64_t best_num = lbound;
  unsigned int longest_len = collatzLen(lbound);

  for (uint64_t num = lbound + 1; num <= rbound; num++) {
    unsigned int current_len = collatzLen(num);
    if (current_len > longest_len) {
      longest_len = current_len;
      best_num = num;
    }
  }

    *maxlen = longest_len;
    return best_num;
}
