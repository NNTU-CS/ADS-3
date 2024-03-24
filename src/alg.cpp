// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  //  поместить сюда реализацию алгоритма
  int cnt = 0;
  if (size == 1) {
    for (int i = 0; i < size; ++i) {
      if (arr[i] == value) {
        cnt++;
        return cnt;
      }
    }
    return 0;
  } else {
    return cbinsearch(arr, size / 2, value) +
    cbinsearch(arr + size/2, size - size / 2, value);
  }
}
