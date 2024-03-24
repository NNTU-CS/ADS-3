// Copyright 2021 NNTU-CS

int cbinsearch(int* arr, int size, int value) {
    int left = 0;
    int right = size - 1;
    int count = 0;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (arr[middle] == value) {
            count++;
            int i = middle - 1;
            while (i >= 0 && arr[i] == value) {
                count++;
                i--;
            }
            i = middle + 1;
            while (i < size && arr[i] == value) {
                count++;
                i++;
            }
            return count;
        } else if (arr[middle] < value) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return count;
}
