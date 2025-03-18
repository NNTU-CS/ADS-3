// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t startNum) {
  uint64_t currentMax = startNum;
  uint64_t value = startNum;

  while (value > 1) {
    if (value % 2 == 0) {
      value = value / 2;
    } else {
      if (value > UINT64_MAX / 3) {
        return currentMax;
      }
      value = value * 3 + 1;
      if (value > currentMax) {
        currentMax = value;
      }
    }
  }
  return currentMax;
}

unsigned int collatzLen(uint64_t initialNum) {
  unsigned int sequenceLength = 1;
  uint64_t currentValue = initialNum;

  while (currentValue > 1) {
    if (currentValue % 2 == 0) {
      currentValue = currentValue / 2;
    } else {
      if (currentValue > UINT64_MAX / 3) {
        return sequenceLength;
      }
      currentValue = currentValue * 3 + 1;
    }
    sequenceLength++;
  }
  return sequenceLength;
}

unsigned int seqCollatz(unsigned int* maxLengthPtr,
                      uint64_t lowerBound,
                      uint64_t upperBound) {
  unsigned int longestStart = lowerBound;
  unsigned int currentLength = 0;
  *maxLengthPtr = 0;

  for (uint64_t currentNum = lowerBound; currentNum <= upperBound; currentNum++) {
    currentLength = collatzLen(currentNum);
    if (currentLength > *maxLengthPtr) {
      *maxLengthPtr = currentLength;
      longestStart = (unsigned int)currentNum;
    }
  }

  return longestStart;
}
