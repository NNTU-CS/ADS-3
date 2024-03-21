// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
int count = 0;
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == value) {
            count++;
            int left = mid - 1;
            int right = mid + 1;

            while (left >= 0 && arr[left] == value) {
                count++;
                left--;
            }

            while (right < size && arr[right] == value) {
                count++;
                right++;
            }

            return count;
        }

        if (arr[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return count;
}

