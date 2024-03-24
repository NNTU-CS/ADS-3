// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int cnt = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] == value)
      cnt += 1;
  }
  return cnt;
}
