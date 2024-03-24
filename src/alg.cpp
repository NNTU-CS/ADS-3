// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int count = 0;
    int lowg = 0;
    int highg = size-1;

    while (lowg <= highg) {
        int mid = (lowg+highg)/2;
        if (arr[mid] < value) {
            lowg = mid + 1;
        } else if (arr[mid] > value) {
            highg = mid-1;
        } else {
            count++;
            int arg1 = mid-1;
            mid++;
            while (arr[mid] == value) {
                count++;
                mid++;
            }
            while (arr[arg1] == value) {
                count++;
                arg1--;
            }
            break;
        }
    }
    return count;
}
