// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  //  поместить сюда реализацию алгоритма
  return 0; // если ничего не найдено
    int left = 0;
    int right = size;
    int iCount = 0;
    int mid = 0;
    int ark = -1;
  
    while (left <= right) {
      mid = (left + right) / 2;
      if (arr[mid] == value) {
        ark = mid;
      }
      if (ark[mid] < value) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  
    while (arr[ark] == value) {
      iCount++;
      ark++;
    }
    if (iCount == 0) {
      return 0;
    } else {
      return iCount;
    }
}
