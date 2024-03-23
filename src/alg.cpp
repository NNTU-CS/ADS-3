// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int leftborder = 0;
    int rightborder = size - 1;
    int counter = 0;
    while (leftborder <= rightborder) {
        int middle = (leftborder + rightborder) / 2;
        if (arr[middle] == value) {
            counter++;
            int i = middle - 1;
            while (i >= 0 && arr[i] == value) {
                counter++;
                i--;
            }
            i = middle + 1;
            while (i < size && arr[i] == value) {
                i++;
                counter++;
            }
            break;
        } else if (arr[middle] < value) {
            leftborder = middle + 1;
        } else {
            rightborder = middle - 1;
        }
    }
    return counter;
}
