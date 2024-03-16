// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int cntr = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] == value) {
      cntr += 1;
    }
  }
  if (cntr > 0)
    return cntr;
  else
    return 0;
}
