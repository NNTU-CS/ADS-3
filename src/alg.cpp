// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int iTemp = size / 2;
    int counter = 0;
    bool bFlag = true;
    if (arr[iTemp] == value) {
        while (arr[iTemp] == value && iTemp >= 0) {
            iTemp--;
        }
        iTemp++;
        while (arr[iTemp] == value && iTemp < size) {
            iTemp++;
            counter++;
        }
        return counter;
    }
    while (iTemp >= 0 && iTemp < size && bFlag) {
        if (arr[iTemp] == value) {
            while (iTemp >= 0 && iTemp < size && arr[iTemp] == value) {
                counter++;
                if (arr[iTemp] < arr[size / 2]) {
                    iTemp--;
                } else {
                    iTemp++;
                }
            }
            bFlag = false;
        } else if (arr[iTemp] > value && arr[iTemp - 1] < value) {
            return 0;
        } else if (arr[iTemp + 1] > value && arr[iTemp] < value) {
            return 0;
        } else if (arr[iTemp] > value) {
            iTemp--;
        } else {
            iTemp++;
        }
    }
    return counter;
}
