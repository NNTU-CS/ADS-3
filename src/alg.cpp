// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int k = 0;
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (arr[mid] == value) {
            k++;
            int pup = mid - 1;
            while (pup >= 0 && arr[pup] == value) {
                k++;
                pup--;
            }
            pup = mid + 1;
            while (pup < size && arr[pup] == value) {
                k++;
                pup++;
            }
            break;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return k;
}
