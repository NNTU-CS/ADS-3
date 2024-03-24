// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int count = 0;
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            count++;
            int leftPos = mid - 1;
            while (leftPos >= 0 && arr[leftPos] == value) {
                count++;
                leftPos--;
            }
            int rightPos = mid + 1;
            while (rightPos < size && arr[rightPos] == value) {
                count++;
                rightPos++;
            }
            return count;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0; // если ничего не найдено
}
