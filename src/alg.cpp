// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    uint64_t count = 0;
    for (uint64_t i = 0; i < size; i++) {
        if (arr[i] == value) {
            count++;
        }
    }
    return count;
}
