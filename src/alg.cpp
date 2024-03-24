// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
int left = 0;
int right = size - 1;
int count = 0;
while (left <= right) {
    int centre = (left + right) / 2;
    if (arr[centre] == value) {
        count++;
        int temp = centre - 1;
        while (temp >= left && arr[temp] == value) {
        count++;
        temp--;
      }
      temp = centre + 1;
      while (temp <= right && arr[temp] == value) {
        count++;
        temp++;
      }
      return count;
    } else if (arr[centre] < value) {
      left = centre +1;
    } else {
      right = centre - 1;
    }
    }
    return 0;
}

