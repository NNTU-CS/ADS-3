// Copyright 2021 NNTU-CS

int cbinsearch(int* arr, int size, int value) {
    if (size == 1) {
        if (*(arr) == value) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return cbinsearch(arr, size / 2, value) + \
            cbinsearch(arr + (size / 2), size / 2 + size % 2, value);
    }
}
