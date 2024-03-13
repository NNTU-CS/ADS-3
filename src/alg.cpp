// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    bool flag = false;
    int l = 0;
    int r = size - 1;
    int m = 0, otv = 0, res = 1;
    while ((l <= r) && (flag != true)) {
        m = (l + r) / 2;
        if (arr[m] == value) {
            flag = true;
            otv = m;
        }
        if (arr[m] > value) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    while (arr[m] == value) {
        m++;
        if (arr[m] == value) res++;
    }
    m = otv;
    while (arr[m] == value) {
        m--;
        if (arr[m] == value) res++;
    }
    if (flag == false) return 0;
    return res;
}
