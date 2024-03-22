// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int count = 0;
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == value) {
            count++;
            for (int i = mid - 1; i >= 0; i--) {
                if (arr[i] == value) {
                    count++;
                } else {
                    break;
                }
            }
            for (int i = mid + 1; i < size; i++) {
                if (arr[i] == value) {
                    count++;
                } else {
                    break;
                }
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
