// Copyright 2021 NNTU-CS
#include <iostream>

int cbinsearch(int *arr, int size, int value) {
    int count = 0;
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            count++;
            int temp = mid - 1;
            while (temp >= 0 && arr[temp] == value) {
                count++;
                temp--;
            }
            temp = mid + 1;
            while (temp < size && arr[temp] == value) {
                count++;
                temp++;
            }
            break;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return count;
}
int main() {
    int arr[] = {1, 2, 2, 3, 4, 5, 5, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int value = 5;
    std::cout << value << ": " << cbinsearch(arr, size, value) << std::endl;
  return 0;
}
