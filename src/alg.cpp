// Copyright 2021 NNTU-CS

int cbinsearch(int* arr, int size, int value) {
    int count = 1;
    int leftborder = 0;
    int rightborder = size - 1;
    while (leftborder <= rightborder) {
        int center = (leftborder + rightborder) / 2;
        if (*(arr + center) == value) {
                int i = center - 1;
                while (*(arr + (i)) == value) {
                    count += 1;
                    i--;
                }
                int j = center + 1;
                while (*(arr + (j)) == value) {
                    count += 1;
                    j++;
                }
            return count;
        } else if (*(arr + center) < value) {
            leftborder = center + 1;
        } else {
            rightborder = center - 1;
        }
    }
    return 0;
}
