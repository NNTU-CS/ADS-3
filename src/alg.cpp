// Copyright 2021 NNTU-CS

#include <cstdint>

int cbinsearch(int *arr, int size, int value) {
    int count = 0;
    int lower = 0;
    int high = size - 1;
    while (lower <= high) {
        int mid = (lower + high) / 2;
        if (arr[mid] < value) {
            lower = mid + 1;
        } else if (arr[mid] > value) {
            high = mid - 1;
        } else {
            count++;
            int per = mid-1;
            mid++;
            while (arr[mid] == value) {
                count++;
                mid++;
            }
            while (arr[per] == value) {
                count++;
                per--;
            }
            break;
        }
    }
    return count;
}
