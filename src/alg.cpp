// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int l = 0;
  int r = size - 1;
  int count = 0;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (arr[mid] < value) {
      l = mid + 1;
    } else if (arr[mid] > value) {
      r = mid - 1;
    } else {
      count++;
      int temp = mid;
      while (temp > 0 && arr[temp - 1] == value) {
        count++;
        temp--;
      }
      temp = mid;
      while (temp < size - 1 && arr[temp + 1] == value) {
        count++;
        temp++;
      }
      break;
    }
  }
  return count;
}
