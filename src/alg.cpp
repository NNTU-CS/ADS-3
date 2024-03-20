int cbinsearch(int *arr, int size, int value) {
  int count = 0;
  int left = 0;
  int right = size - 1;
  while (right >= left) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == value) {
      int index = mid - 1;
      while (index >= 0 && arr[index] == value) {
        count++;
        index--;
      }
      index = mid + 1;
      while (index < size && arr[index] == value) {
        count++;
        index++;
      }
      return count;
    }
    else if (arr[mid] < value) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }
  return 0;

}
