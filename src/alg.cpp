// Copyright 2021 NNTU-CS

int cbinsearch(int* arr, int size, int value) {
    int count = 0;
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == value) {
            count++;
            int i = mid - 1;
            while (i >= 0 && arr[i] == value) {
                count++;
                i--;
            }
            i = mid + 1;
            while (i < size && arr[i] == value) {
                count++;
                i++;
            }
            break;
        }
        else if (arr[mid] < value) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return count > 0 ? count : 0;
}
