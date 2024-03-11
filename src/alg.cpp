// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int counter = 0;
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int average = left + (right - left) / 2;
        if (arr[average] == value) {
            counter++;
        int i = average - 1;
            while (i >= 0 && arr[i] == value) {
                counter++;
                i--;
            }
            int j = average + 1;
            while (j < size && arr[j] == value) {
                counter++;
                j++;
            }
            return counter;
            } else if (arr[average] < value) {
            left = average + 1;
            } else {
            right = average - 1;
        }
    }
  return 0; // если ничего не найдено
}
