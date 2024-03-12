// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int count = 0;
  int left = 0;
  int right = size - 1;
  while (right >= left) {
    int middle = left + (right - left) / 2;
    if (arr[middle] == value) {
      count++;
      int index = middle - 1;
      while (index >= 0 && arr[index] == value) {
        count++;
        index--;
      }
      index = middle + 1;
      while (index < size && arr[index] == value) {
        count++;
        index++;
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
