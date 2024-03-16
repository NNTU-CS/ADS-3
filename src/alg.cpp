// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int leftIndex = 0;
  int rightIndex = size - 1;
  int count = 0;
  while (leftIndex <= rightIndex) {
    int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
    if (arr[middleIndex] == value) {
      count++;
      int leftInd = middleIndex - 1;
      int rightInd = middleIndex + 1;
      while (leftInd >= 0 && arr[leftInd] == value) {
        count++;
        leftInd--;
      }
      while (rightInd < size && arr[rightInd] == value) {
        count++;
        rightInd++;
      }
      return count;
    } else if (arr[middleIndex] < value) {
      leftIndex = middleIndex + 1;
    } else {
      rightIndex = middleIndex - 1;
    }
  }
  return 0; // если ничего не найдено
}
