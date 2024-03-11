// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int k = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            k += 1;
        }
    }
    if (k > 0) {
        return k;
    } else {
        return 0;
    }
}
