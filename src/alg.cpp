// Copyright 2022 NNTU-CS
#include <cmath>
#include <cstdint>
#include "alg.h"



double pown(double value, uint16_t n) {
  double result = 1.0;
  for (uint16_t i = 0; i < n; ++i) {
    result *= value;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  uint64_t result = 1;
  for (uint16_t i = 1; i <= n; ++i) {
    result *= i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  if (n == 0) {
    return 1.0;
  }
  return (pown(x, n) / fact(n));
}

double expn(double x, uint16_t count) {
  double result = 1.0;
    for (uint16_t i = 1; i <= count; ++i) {
      result += calcItem(x, i);
    }
  return result;
}

double sinn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    double term = (n % 2 == 0 ? 1 : -1) * pown(x, 2 * n + 1) / fact(2 * n + 1);
    sum += term;
    }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    double term = (n % 2 == 0 ? 1 : -1) * pown(x, 2 * n) / fact(2 * n);
    sum += term;
  }
  return sum;
}
