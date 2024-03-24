// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int cnt = 0, left = 0, right = size - 1;
  while (right >= left) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == value) {
      cnt++;
      int ind = mid - 1;
      while (ind >= 0 && arr[ind] == value) {
        cnt++;
        ind--;
      }
      ind = mid + 1;
      while (ind < size && arr[ind] == value) {
        cnt++;
        ind++;
      }
      return cnt;
    } else if (arr[mid] < value) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return 0;
}
