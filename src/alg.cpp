// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int count = 0;
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            count++;
            int idx = mid - 1;
            while (idx >= 0 && arr[idx] == value) {
                count++;
                idx--;
            }
            idx = mid + 1;
            while (idx < size && arr[idx] == value) {
                count++;
                idx++;
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
