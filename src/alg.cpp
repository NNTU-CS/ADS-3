// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int l = 0;
    int r = size - 1;
    int mid = (r + l) / 2;
    int counter = -1;
    while (l <= r) {
        if (arr[mid] == value) {
            counter += 2;
            break;
        }
        if (arr[mid] > value)
            r = mid - 1;
        else
            l = mid + 1;
        mid = (r + l) / 2;
    }
    if (counter == -1) return 0;
    for (int i = mid - 1; i >= 0; i--) {
        if (arr[i] == value)
            counter++;
        else
            break;
    }
    for (int i = mid + 1; i <= size - 1; i++) {
        if (arr[i] == value)
            counter++;
        else
            break;
    }
    return counter;
}
