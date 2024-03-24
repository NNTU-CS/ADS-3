// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int count = 0;
  int left = 0, right = size-1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == value) {
        count++;
        int i = mid + 1;
        while (i < size && arr[i] == value) {
            count++;
            i++;
        }
        i = mid - 1;
        while (i >= 0 && arr[i] == value) {
            count++;
            i--;
        }
        break;
    }
    if (arr[mid] < value)
        left = mid + 1;
    if (arr[mid] > value)
        right = mid - 1;
  }
  return count;
}
