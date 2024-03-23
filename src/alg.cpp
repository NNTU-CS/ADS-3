// Copyright 2021 NNTU-CS

int cbinsearch(int* arr, int size, int value) {
int count = 0;
int  left_index = 0;
int right_index = size - 1;
int i = 0;
int middle = 0;
while (left_index <= right_index) {
    int middle = left_index + (right_index - left_index) / 2;
    if (arr[middle] == value) {
        count++;
        for (i = middle - 1; i >= 0 && arr[i] == value; --i) {
          count++;
        }
         for (i = middle + 1; i < size && arr[i] == value; ++i) {
         count++;
         }
         return count;
         } else if (arr[middle] < value) {
          left_index = middle + 1;
      } else {
     right_index = middle - 1;
    }
}
     return count;
}
