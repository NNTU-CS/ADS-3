// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t MaxValue = 0;
  uint64_t OrdinaryValue = num;
  while (OrdinaryValue != 1){
    if (OrdinaryValue % 2 == 0){
      OrdinaryValue = OrdinaryValue / 2;
    }
    else{
      OrdinaryValue = OrdinaryValue * 3 + 1;
    }
    if (MaxValue < OrdinaryValue){
      MaxValue = OrdinaryValue;
    }
  }
  return MaxValue;
}

unsigned int collatzLen(uint64_t num) {
  uint64_t OrdinaryValue = num;
  unsigned int Len = 1;
  while (OrdinaryValue != 1){
    if (OrdinaryValue % 2 == 0){
      OrdinaryValue = OrdinaryValue / 2;
    }
    else{
      OrdinaryValue = OrdinaryValue * 3 + 1;
    }
    Len += 1;
  }
  return Len;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int MaxLen = 0;
  unsigned int MaxI = 0;
  for (unsigned int i = lbound; i <= rbound; i++){
    unsigned int Len = collatzLen(i);
    if (Len > MaxLen){
      MaxLen = Len;
      MaxI = i;
    }
  }
  *maxlen = MaxLen;
  return MaxI;
}
