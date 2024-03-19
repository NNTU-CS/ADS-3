// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
int f = 0, l = size - 1, m = 0, count = 0;
while (f <= l && m != -10) {
  m = f + ((l - f) / 2);
  if (value == arr[m]) {
    while (m > 0 && arr[m-1] == value) {
      m--;
    }
    while (arr[m] == value) {
      m++;
      count++;
    }
  }
  if (count > 0) {
    m = -10;
  } else if (value > arr[m]) {
    f = m + 1;
  } else if (value < arr[m]) {
    l = m - 1;
  } else {
    m = -10;
  }
}
return count;
}
