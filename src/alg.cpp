// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
int count = 0;
int left = 0, righ = size - 1;
while (left <= righ) {
int mid = (left+righ) / 2;
if (arr[mid] == value) {
int a = mid - 1;
while (arr[mid] == value) {
if (arr[mid] == value) {
count++;
mid++;
}
}
while (arr[a] == value) {
if (arr[a] == value) {
count++;
--a;
}
}
return count;
} else if (arr[mid] < value) {
left = mid + 1;
} else {
righ = mid - 1;
}
}
return count;
}
