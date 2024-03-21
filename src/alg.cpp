// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int leftbound = 0;
  int rightbound = size - 1;
  int counter = 0;
  while (leftbound <= rightbound) {
    int center = (leftbound + rightbound) / 2;
    if (arr [center] == value) {
      counter++;
      int temp = center - 1;
      while (temp >= leftbound && arr [temp] == value) {
        counter++;
        temp--;
      }
      temp = center + 1;
      while (temp <= rightbound && arr [temp] == value) {
        counter++;
        temp++; 
      }
      return counter;
    } else if (arr [center] < value) {
      leftbound = center +1;
    } else {
      rightbound = center - 1;
    }
  }
  return 0; // если ничего не найдено
}
