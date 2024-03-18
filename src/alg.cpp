// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int low = 0;
    int high = size - 1;
    int counter = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] < value) {
            low = mid + 1;
        } else if (arr[mid] > value) {
            high = mid - 1;
        } else {
            counter++;
            int iPer = mid - 1;
            mid++;
            while (arr[mid] == value) {
                counter++;
                mid++;
            }
            while (arr[iPer] == value) {
                counter++;
                iPer--;
            }
            break;
        }
    } return counter;
}

