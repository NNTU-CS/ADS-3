// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int left = 0;
  int right = size - 1;
  int counter = 0;

  while (left <= right) {
    int middle = left + (right - left) / 2;

    if (arr[middle] == value) {
      counter++;
      int tempMiddle = middle;

      while (tempMiddle > 0 && arr[tempMiddle - 1] == value) {
        counter++;
        tempMiddle--;
      }

      tempMiddle = middle;

      while (tempMiddle < size - 1 && arr[tempMiddle + 1] == value) {
        counter++;
        tempMiddle++;
      }

      return counter;
    } else if (arr[middle] < value)
      left = middle + 1;
    else
      right = middle - 1;
  }

  return 0;
}