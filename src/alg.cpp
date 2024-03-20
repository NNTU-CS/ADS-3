// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int count = 0;
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (arr[middle] == value) {
            count++;
            int neighL = middle - 1;
            while (neighL >= 0 && arr[neighL] == value) {
                count++;
                neighL--;
            }
            int iright = middle + 1;
            while (iright < size && arr[iright] == value) {
                count++;
                iright++;
            }
            return count;
        } else if (arr[middle] < value) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return 0;
}
