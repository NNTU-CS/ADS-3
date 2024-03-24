// Copyright 2021 NNTU-CS
int cbinsearch(int* arr, int size, int value) {
    int l = 0, r = size - 1, count = 0;
    while (l <= r) {
        int mid = l+(r-l) / 2;
        if (arr[mid] == value) {
            count++;
            int tp = mid - 1;
            while (tp >= 0 && arr[tp] == value) {
                count++;
                tp--;
            }
            tp = mid + 1;
            while (tp < size && arr[tp] == value) {
                count++;
                tp++;
            }
            break;
        } else if (arr[mid] < value) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return count;
}
