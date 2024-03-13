// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int count = 0;
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (arr[middle] == value) {
            count++;
            int iLow = middle - 1;
            while (iLow >= 0 && arr[iLow] == value) {
                count++;
                iLow--;
            }
            int iHigh = middle + 1;
            while (iHigh < size && arr[iHigh] == value) {
                count++;
                iHigh++;
            }
            return count;
        } else if (arr[middle] < value) {
            low = middle + 1;
        } else {
            high = middle - 1;
        }
    }
    return 0;
}
