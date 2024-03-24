// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int count = 0;
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int midd = left + (right - left) / 2;
        if (arr[midd] < value) {
            left = midd + 1;
        } else if (arr[midd] > value) {
            right = midd - 1;
        } else if (arr[midd] == value) {
            count++;
            right = midd + 1;
            while (arr[right] == value) {
                count++;
                right++;
            }
            left = midd - 1;
            while (arr[left] == value) {
                count++;
                left--;
            }
            break;
        }
    }
    return count;
}
