// Copyright 2021 NNTU-CS
int cbinsearch(int* arr, int size, int value) {
  int left = 0, right = size - 1;
  int middle = (right - left + 1) / 2, counter = 0;
  int stop = 0;
  while (arr[middle] != value) {
    if (arr[middle] < value) {
      left = middle;
    } else if (arr[middle] > value) {
      right = middle;
    }
    middle = (right - left) / 2;
    if (right - left <= 1) {
      counter -= 1;
      break;
    }
    stop += 1;
    if (stop == 10) {
      return 0;
    }
  }
  counter += 1;
  bool one = true, two = true;
  int index1 = middle - 1, index2 = middle + 1;
  while (true) {
    if (one) {
      if (index1 < 0 || index1 > size - 1) {
        one = false;
      } else {
        if (arr[index1] == value) {
          counter += 1;
        }
      }
    }
    if (two) {
      if (index2 < 0 || index2 > size - 1) {
        two = false;
      } else {
        if (arr[index2] == value) {
          counter += 1;
        }
      }
    }
    index1 -= 1;
    index2 += 1;
    if (!one && !two) {
      break;
    }
  }
  return counter;  // если ничего не найдено
}
