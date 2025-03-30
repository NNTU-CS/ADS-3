// Copyright 2025 NNTU-CS
#include <iostream>
#include <cstdint>

unsigned int collatzLen(uint64_t num) {
  unsigned int length = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    length++;
  }
  return length;
}

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxVal = num;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    if (num > maxVal) {
      maxVal = num;
    }
  }
  return maxVal;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, uint64_t rbound) {
  unsigned int longestLen = 0;
  uint64_t numberWithLongestSeq = 0;

  for (uint64_t i = lbound; i <= rbound; ++i) {
    unsigned int currentLen = collatzLen(i);
    if (currentLen > longestLen) {
      longestLen = currentLen;
      numberWithLongestSeq = i;
    }
  }

  *maxlen = longestLen;
  return numberWithLongestSeq;
}

int main() {
  unsigned int maxlen = 0;
  uint64_t lbound = 2;
  uint64_t rbound = 1000000;
  uint64_t resultNum = seqCollatz(&maxlen, lbound, rbound);
  std::cout << resultNum << "\n";
  std::cout << maxlen << "\n";
  std::cout << collatzMaxValue(resultNum) << "\n";

  return 0;
}

