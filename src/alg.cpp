// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  //  поместить сюда реализацию алгоритма
  int leftBound = 0;
  int rightBound = size - 1;
  int count = 0;
  while (leftBound <= rightBound) {
    int center = (leftBound + rightBound) / 2;
    if (arr[center] == value) {
      count++;
      int buf = center - 1;
      while (buf >= leftBound && arr[buf] == value) {
        count++;
        buf--;
      }
      buf = center + 1;
      while (buf <= rightBound && arr[buf] == value) {
        count++;
        buf++;
      }
      return count;
    } else if (arr[center] < value) {
      leftBound = center + 1;
    } else {
      rightBound = center - 1;
    }
  }
  return 0; // если ничего не найдено
}
