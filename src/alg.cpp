// Copyright 2021 NNTU-CS
#include <cstdint>

int cbinsearch(int *arr, int size, int value) {
    int l = 0;
    int r = size - 1;
    int count = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == value) {
            count++;
            int t = mid - 1;
            while (t >= 0 && arr[t] == value) {
                count++;
                t--;
            }
            t = mid + 1;
            while (t < size && arr[t] == value) {
                count++;
                t++;
            }
            return count;
        } else if (arr[mid] < value) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return count;
}


