// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int low = 0;
    int high = size - 1;
    int count = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] < value) {
            low = mid + 1;
        } else if (arr[mid] > value) {
            high = mid - 1;
        } else {
            count++;
            int index = mid - 1;
            mid++;
            while (arr[mid] == value) {
                count++;
                mid++;
            }
            while (arr[index] == value) {
                count++;
                index--;
            }
            break;
        }
    } return count;
}
