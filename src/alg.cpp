// Copyright 2021 NNTU-CS

int cbinsearch(int* arr, int size, int value) {
    bool flag = false;
    int x = 0;
    int y = size - 1;
    int z = 0, otv = 0, res = 1;
    while ((x <= y) && (flag != true)) {
        z = (x + y) / 2;
        if (arr[z] == value) {
            flag = true;
            otv = z;
        }
        if (arr[z] > value) {
            y = z - 1;
        }
        else {
            x = z + 1;
        }
    }
    while (arr[z] == value) {
        z++;
        if (arr[z] == value) res++;
    }
    z = otv;
    while (arr[z] == value) {
        z--;
        if (arr[z] == value) res++;
    }
    if (flag == false) return 0;
    return res;
}
