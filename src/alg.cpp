// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t nowMax = 0;
  uint64_t nowInt = num;
  while (nowInt != 1) {
    if (nowInt > nowMax) {
      nowMax = nowInt;
    }
    if (nowInt % 2 == 0) {
      nowInt /= 2;
    } else {
      nowInt = nowInt * 3 + 1;
    }
  }
  return nowMax;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int nowLen = 1;
  uint64_t nowInt = num;
  while (nowInt != 1) {
    nowLen++;
    if (nowInt % 2 == 0) {
      nowInt /= 2;
    } else {
      nowInt = nowInt * 3 + 1;
    }
  }
  return nowLen;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int nowInt = 0;
  for (uint64_t i = lbound; i <= rbound; i++) {
    if (collatzLen(i) > *maxlen) {
      nowInt = i;
      *maxlen = collatzLen(i);
    }
  }
  return nowInt;
}
