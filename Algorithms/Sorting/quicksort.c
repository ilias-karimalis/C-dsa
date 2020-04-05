#include <stdio.h>

int partition(int* arr, int p, int r) {
    int temp;
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (arr[j] <= x) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp;
    return i + 1;
}

void quickSort(int* arr, int p, int r) {
    if (p < r) {
        int q = partition(arr,p,r);
        quickSort(arr, p, q-1);
        quickSort(arr, q+1, r);
    }
}

int main() {
    int len = 5;
    int arr[5] = {7, 39, 1, 92, 0};
    quickSort(arr, 0, len);
    for (int i = 0; i < len; i++) {
        printf("%d\n", arr[i]);
    }
}
