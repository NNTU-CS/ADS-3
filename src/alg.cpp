// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int left = 0;
  int right = size - 1;
  int counter = 0;
  while (left <= right) {
    int centre = (left + right) / 2;
    if (arr[centre] == value) {
      counter++;
      int temp = centre - 1;
      while (temp >= left && arr[temp] == value) {
        counter++;
        temp--;
      }
      temp = centre + 1;
      while (temp <= right && arr[temp] == value) {
        counter++;
        temp++;
      }
      return counter;
    } else if (arr[centre] < value) {
      left = centre +1;
    } else {
      right = centre - 1;
    }
  }
  return 0; // если ничего не найдено
}
