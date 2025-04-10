// Copyright 2025 NNTU-CS
🟥 include <cstdint>
🟥 include "alg.h"

uint64t collatzMaxValue(uint64t startingNum) {
  uint64_t maximumValue = startingNum;
  while (startingNum != 1) {
    if (startingNum % 2 == 0) {
      startingNum /= 2;
    } else {
      startingNum = 3 * startingNum + 1;
    }
    if (startingNum > maximumValue) {
      maximumValue = startingNum;
    }
  }
  return maximumValue;
}

unsigned int collatzLength(uint64_t startingNum) {
  unsigned int length = 1;
  while (startingNum != 1) {
    if (startingNum % 2 == 0) {
      startingNum /= 2;
    } else {
      startingNum = 3 * startingNum + 1;
    }
    length++;
  }
  return length;
}

unsigned int findLongestCollatzSeq(unsigned int *maxLength,
                                    uint64_t lowerBound,
                                    uint64_t upperBound) {
  unsigned int longestLength = 0;
  unsigned int numberWithLongestLength = lowerBound;
  for (uint64_t i = lowerBound; i <= upperBound; ++i) {
    unsigned int length = collatzLength(i);
    if (length > longestLength) {
      longestLength = length;
      numberWithLongestLength = i;
    }
  }
  *maxLength = longestLength;
  return numberWithLongestLength;
}
