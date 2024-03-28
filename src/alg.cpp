// Copyright 2021 NNTU-CS

#include <cstdint>

int cbinsearch(int *arr, int size, int value) {
    uint64_t left = 0;
    uint64_t right = size - 1;
    uint64_t count = 0;
    while (left <= right) {
        uint64_t mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            count++;
            uint64_t i = mid - 1;
            while (i >= 0 && arr[i] == value) {
                count++;
                i--;
            }
            i = mid + 1;
            while (i < size && arr[i] == value) {
                count++;
                i++;
            }
            return count;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return count;
}
