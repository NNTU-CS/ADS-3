// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int left = 0;
    int right = size - 1;
    int r;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            r++;
            int i = mid + 1;
            while (i < size && arr[i] == value) {
                r+=1;
                i++;
            }
            i = mid - 1;
            while (i >= 0 && arr[i] == value) {
                r+=1;
                i--;
            }
            return r;
        } 
        else if (arr[mid] >= value) {
            right = mid - 1;
        } 
        else {
            left = mid + 1;
        }
    }
    return 0; // если ничего не найдено
}
