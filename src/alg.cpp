// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int low = 0;
  int high = size - 1;
  int n = 0;
  while (low <= high) {
    int mid = low + ((high - low) / 2);
    if (arr[mid] == value) {
      n = 1;
      int net = mid + 1;
      while ((net < size) && (arr[net] == value)) {
        net++;
        n++;
      }
      net = mid - 1;
      while ((net >= 0) && (arr[net] == value)) {
        net--;
        n++;
      }
      return n;
    } else if (arr[mid] < value) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return 0;
}
