// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  //  поместить сюда реализацию алгоритма
  int k = 0;
  for (int i = 0; arr[i] <= value; i++) {
    if (arr[i] == value)
      k++;
  }
  if (k > 0)
  return k;
  else
  return 0; // если ничего не найдено
}
