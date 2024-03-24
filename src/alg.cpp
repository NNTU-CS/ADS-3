// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int found = 0;
  int left = 0;
  int right = size - 1;
  int middle = 0;
  while ((left <= right)) {
    middle = (left + right) / 2;
    if (arr[middle] == value) {
      int tmp = middle-1;
      while (arr[middle] == value) {
        if (arr[middle] == value) {
          middle++;
          found++;
        } else {
          break;
        }
      }
      while (arr[tmp] == value) {
        if (arr[tmp] == value) {
          --tmp;
          found++;
        } else {
          break;
        }
      }
      break;
    }
    if (arr[middle] > value) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }
    return found;
  return 0;
}
