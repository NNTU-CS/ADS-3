// Copyright 2021 NNTU-CS
int cbinsearch(int *arr, int size, int value) {
    int low = 0;
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (arr[mid] == value) {
            int p = mid - 1;
            while (p >= 0 && arr[p] == value) {
                low++;
                p--;
            }
            p = mid + 1;
            while (p < size && arr[p] == value) {
                low++;
                p++;
            }
            break;
            low++;
        } else {
            right = mid - 1;
        }
    }
    return low;
}
