// Copyright 2021 NNTU-CS

int cbinsearch(int* arr, int size, int value) {
    int count = 0;
    int l = *arr;
    int r = size - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (r - l == 1) {
            return 0;
        }
        if (value > arr[mid]) {
            l = mid;
        } else if (value < arr[mid]) {
            r = mid;
        } else {
            while (arr[mid] == value) {
                mid--;
            }
            mid++;
            while (arr[mid] == value) {
                mid++;
                count++;
            }
            break;
        }
    }
    return count;
}
