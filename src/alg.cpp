// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int count = 0, low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] < value) {
            low = mid + 1;
        } else if (arr[mid] > value) {
            high = mid - 1;
        } else {
            count++;
            int iPerem = mid - 1;
            mid++;
            while (arr[mid] == value) {
                count++;
                mid++;
            }
            while (arr[iPerem] == value) {
                count++;
                iPerem--;
            }
            break;
        }
    }
    return count;
}
