// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int low = 0, count = 0, high = size - 1;
  while (low <= high) {
      int middle = (high + low) / 2;
      if (arr[middle] < value) {
          low = middle + 1;
      } else if (arr[middle] > value) {
          high = middle - 1;
      } else {
          count++;
          int now = middle - 1;
          middle++;
          while (arr[middle] == value) {
              middle++;
              count++;
          }
          while (arr[now] == value) {
              now--;
              count++;
          }
          break;
      }
  }
  return count;
}
