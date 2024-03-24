// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  //  поместить сюда реализацию алгоритма
  return 0; // если ничего не найдено
int cbinSearch(int *arr, int size, int value) {
  int c = 0;
  int l = 0;
  int h = size - 1;
while (l <= h) {
  int mid = l + (h - l) / 2;
  if (arr[mid] == value) {
    c++;
    int left = mid - 1;
    while (left >= 0 && arr[left] == value) {
      c++;
      left--;
    }
    int right = mid + 1;
    while (right < size && arr[right] == value) {
      c++;
      right++;
    }
    return c;
  } else if (arr[mid] < value) {
    l = mid + 1;
  } else {
    h = mid - 1;
  }
}
  return 0;
}
