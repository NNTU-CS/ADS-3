// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int count = 0;
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (arr[mid] == value) {
            count++;
            int p = mid - 1;
            while (p >= 0 && arr[p] == value) {
                count++;
                p--;
            }
            p = mid + 1;
            while (p < size && arr[p] == value) {
                count++;
                p++;
            }
            break;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return count;
}
