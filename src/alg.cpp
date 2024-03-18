// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int count1 = 0, count2 = 0, high = size - 1;
    while (count2 <= high) {
        int mid = count2 + (high - count2) / 2;
        if (arr[mid] == value) {
            count1++;
            int low = mid - 1;
            while (low >= 0 && arr[low] == value) {
                count1++;
                low--;
            }
            int high2 = mid + 1;
            while (high2 < size && arr[high2] == value) {
                count1++;
                high2++;
            }
            return count1;
        } else if (arr[mid] < value) {
            count2 = mid + 1;
        } else {
            high = mid + 1;
        }
    }
    return 0;
}
