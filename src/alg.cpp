// Copyright 2025 NNTU-CS
#include <cstdint>
#include <unordered_map>

static std::unordered_map<uint64_t, unsigned int> collatzCache;

unsigned int collatzLen(uint64_t num) {
  if (num == 1) return 1;
  if (collatzCache.count(num)) return collatzCache[num];
  unsigned int length = 0;
  if (num % 2 == 0)
    length = 1 + collatzLen(num / 2);
  else
    length = 1 + collatzLen(3 * num + 1);
  collatzCache[num] = length;
  return length;
}

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxVal = num;
  while (num != 1) {
    if (num % 2 == 0)
      num /= 2;
    else
      num = 3 * num + 1;
    if (num > maxVal) maxVal = num;
  }
  return maxVal;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, uint64_t rbound) {
  unsigned int maxLength = 0;
  unsigned int resultNum = 0;
  for (uint64_t i = lbound; i <= rbound; ++i) {
    unsigned int length = collatzLen(i);
    if (length > maxLength) {
      maxLength = length;
      resultNum =
          static_cast<unsigned int>(i);
    }
  }
  if (maxlen) *maxlen = maxLength;
  return resultNum;
}

