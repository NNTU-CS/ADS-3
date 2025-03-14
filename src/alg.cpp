uint64_t collatzMaxValue(uint64_t num) {
    uint64_t maxnum = num;
  while (num != 1) {
    if (num % 2 == 0)
      num = num / 2;
    else
      num = 3 * num + 1;
    if (num > maxnum)
      maxnum = num;
  }
  return maxnum;
}

unsigned int collatzLen(uint64_t num) {
    uint64_t i = 1;
  while (num != 1) {
    if (num % 2 == 0)
      num = num / 2;
    else
      num = 3 * num + 1;
    i++;
  }
  return i;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
    unsigned int maxnum = 0;
    for (uint64_t i = lbound; i <= rbound; i++) {
        if (collatzLen(i) > *maxlen) {
            maxnum = i;
            *maxlen = collatzLen(i);
        }
    }
    return maxnum;
}
