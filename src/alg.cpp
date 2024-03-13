// Copyright 2024 NNTU-CS
#include <iostream>
#include <iomanip>

int cbinsearch(int* arr, int size, int value) {
    int count = 0;
    int lft = 0;
    int rght = size - 1;
    while (lft <= rght) {
        int middle = lft + (rght - lft) / 2;
        if (arr[middle] == value) {
            count++;
            int p = middle - 1;
            while (p >= 0 && arr[p] == value) {
                count++;
                p--;
            }
            p = middle + 1;
            while (p < size  && arr[p] == value) {
                count++;
                p++;
            }
            return count;
    } else if (arr[middle] > value) {
        rght = middle - 1;
    } else {
        lft = middle +1;
    }
    }
    return count;
}
