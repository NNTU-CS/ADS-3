// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int leftBorder = 0;
  int rightBorder = size - 1;
  int counter = 0;
  while (leftBorder <= rightBorder) {
    int part = (leftBorder + rightBorder) / 2;
    if (arr[part] == value) {
      counter++;
      int temp = part - 1;
      while (temp >= leftBorder && arr[temp] == value) {
        counter++;
        temp--;
      }
      temp = part + 1;
      while (temp <= rightBorder && arr[temp] == value) {
        counter++;
        temp++;
      }
      return counter;
    }
    if (arr[part] > value) {
      rightBorder = part - 1;
    } else {
      leftBorder = part + 1;
    }
  }
  return counter;
}
