// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int c = 0;
    int l = 0;
    int r = size - 1;

    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == value) {
            c++;
            for (int i = m - 1; i >= 0; i--) {
                if (arr[i] == value) {
                    c++;
                } else {
                    break;
                }
            }
            for (int i = m + 1; i < size; i++) {
                if (arr[i] == value) {
                    c++;
                } else {
                    break;
                }
            }
            break;
        } else if (arr[m] < value) {
            l = m + 1;
        } else {
           r = m - 1;
        }
    }
    return c;
}
