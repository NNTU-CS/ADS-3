// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int count = 0;
  if (size == 1) {
    for (int i = 0; i < size; ++i) {
      if (arr[i] == value) {
        count++;
        return count;
      }
    }
    return 0;
  } else {
    return cbinsearch(arr, size / 2, value) +
    cbinsearch(arr + size/2, size - size / 2, value);
  }
}
