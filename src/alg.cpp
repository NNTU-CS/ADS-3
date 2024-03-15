// Copyright 2021 NNTU-CS
#include "alg.h"
#include <iostream>
#include <cstdint>

int cbinsearch(int *arr, int size, int value) {
  int left = 0;
  int right = size - 1;
  int count = 0;
  while (left <= right) {
      int middle = left + (right - left) / 2;
      if (arr[middle] == value) {
          count++;
          int leftind = middle - 1;
          int rightind = middle + 1;
          while (leftind >= 0 && arr[leftind] == value) {
              count++;
              leftind--;
          }
          while (rightind < size && arr[rightind] == value) {
              count++;
              rightind++;
          }
          return count;
      } else if (arr[middle] < value) {
          left = middle + 1;
      } else {
          right = middle - 1;
      }
  }
  return 0;
}
