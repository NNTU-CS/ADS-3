// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int counter = 0;
  int ind1 = 0;
  int ind2 = size - 1;
  int midle = 0;
  while (ind1 <= ind2) {
    int midle = ind1 + (ind2 - ind1) / 2;
    if (arr[midle] == value) {
      counter++;
      int left = midle - 1;
      while (left >= 0 && arr[left] == value) {
        counter++;
        left--;
      }
      int right = midle + 1;
      while (right < size && arr[right] == value) {
        counter++;
        right++;
      }
      return counter;
    } else if (arr[midle] < value) {
      ind1 = midle + 1;
    } else {
      ind2 = midle - 1;
    }
  }
  return 0; // если ничего не найдено
}
