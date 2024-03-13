// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int k = 0;
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int centr = left + (right - left) / 2;
        if (arr[centr] == value) {
            k++;
            int i = centr + 1;
            while (i < size && arr[i] == value) {
                k+=1;
                i++;
            }
            i = centr - 1;
            while (i >= 0 && arr[i] == value) {
                k+=1;
                i--;
            }
            return k;
        } else if (arr[centr] >= value) {
            right = centr - 1;
        } else {
            left = centr + 1;
        }
    }
    return 0;
}
