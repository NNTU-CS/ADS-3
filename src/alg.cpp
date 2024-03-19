// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
int count = 0;
  int left = 0;
  int right = size - 1;
  for (int i = 0; i < size; i++) {
    int mid = (left + right) / 2;
    if (arr[mid] > value)
      left = mid + 1;
    else if (arr[mid] < value)
      right = mid - 1;
    else
      count++;
    int k = mid + 1;
    while(arr[k] == value)
      count++;
      i++;
    int j = mid - 1;
    while(arr[j] == value)
      count++;
      j--;
  }
  return count;
}
