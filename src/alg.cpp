// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int amount = 0;
    int left = 0, right = size - 1, middle;
    do {
        middle = (left + right) / 2;

        if (arr[middle] == value) {
            while (middle > 0 && arr[middle - 1] == value) {
                middle--;
            }
            while (middle < size && arr[middle] == value) {
                amount++;
                middle++;
            }
            return amount;
        } else if (arr[middle] > value) {
            right = middle - 1;
        } else if (arr[middle] < value) {
            left = middle + 1;
        }
    } while (right >= left);

    return amount;
}
