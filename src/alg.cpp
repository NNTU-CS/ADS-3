// Copyright 2021 NNTU-CS
int cbinsearch(int *arr, int size, int value) {
    int low = 0;
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (arr[mid] == value) {
            low++;
            } else {
                right = mid - 1;
            }
        }
        return low;
}
