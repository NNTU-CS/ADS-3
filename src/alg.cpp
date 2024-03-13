// Copyright 2021 NNTU-CS

int cbinsearch(int* arr, int size, int value) {
    if (size == 1) {
        if (arr[0] == value) {
            return 1;
        }
        return 0;
    }
    return cbinsearch(arr, size / 2, value)
    + cbinsearch(arr + size / 2, size - size / 2, value);
}
