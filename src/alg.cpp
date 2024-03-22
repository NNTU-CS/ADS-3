// Copyright 2021 NNTU-CS

int cbinsearch(int* arr, int size, int value) {
  int left = 0, right = size, temp = size / 2, k = 0;
  while (true) {
    if (arr[temp] > value) {
      right = temp;
      temp -= (right - left) / 2;
    } else if (arr[temp] == value) {
      for (int i = temp; i > 0; i--) {
        if (arr[i] != value) {
          left = i + 1;
          break;
        }
      }
      for (int i = temp; i < size; i++) {
        if (arr[i] != value) {
          right = i - 1;
          break;
        }
      }
      left = 0;
      right = size;
      break;
    } else {
      left = temp;
      temp += (right - left) / 2;
    }
  }
  for (int i = left; i < right; i++) {
    if (arr[i] == value)
      k++;
    }
    return k;
}
