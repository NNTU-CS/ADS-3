// Copyright 2021 NNTU-CS

#include <cstdint>

int cbinsearch(int *arr, int size, int value) {
    uint64_t p = 0;
    for (uint64_t i = 0; i < size; i++) {
        if (arr[i] == value) {
            p++;
        }
    }
    return p;
}
