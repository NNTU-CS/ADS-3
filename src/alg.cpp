// Copyright 2021 NNTU-CS
int cbinsearch(int *arr, int size, int value) {
    int64 low = 0;
    int64 left = 0;
    int64 right = size - 1;
    while (left <= right) {
        int64 mid = (right + left) / 2;
        if (arr[mid] == value) {
            low++;
        } else {
            right = mid - 1;
        }
    }
    return low;
}
