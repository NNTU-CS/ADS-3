// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  //  поместить сюда реализацию алгоритма
  return 0; // если ничего не найдено
  int a = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] == value) {
      a += 1;
    }
  }
  if (a > 0)
    return a;
  else
    return 0;
}
