// Copyright 2025 NNTU-CS
#include <iostream>
#include <cstdint>

unsigned int collatzLen(uint64_t num) {
  unsigned int length = 1;
  while (num != 1) {
      if (num % 2 == 0) {
        num /= 2;
        } else {
          num = 3 * num + 1; // Нечётное
        }
      length++;
    }
  return length;
}

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxVal = num;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2; // Чётное
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
  unsigned int longestLength = 0;
  uint64_t numberWithLongestLength = lbound;

  for (uint64_t i = lbound; i <= rbound; ++i) {
    unsigned int length = collatzLen(i);
    if (length > longestLength) {
      longestLength = length;
      numberWithLongestLength = i;
    }
  }

  *maxlen = longestLength;
  return numberWithLongestLength;
}

int main() {
  unsigned int maxlen = 0;
  uint64_t lbound = 2;
  uint64_t rbound = 1000000; // Обратите внимание на верхний предел

  unsigned int number = seqCollatz(&maxlen, lbound, rbound);
  uint64_t maxValue = collatzMaxValue(number);

  std::cout << number << std::endl;
  std::cout << maxlen << std::endl;
  std::cout << maxValue << std::endl;

  return 0;
}
