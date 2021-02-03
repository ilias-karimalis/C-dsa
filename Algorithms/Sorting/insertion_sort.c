#include <stdio.h>

int* insertionSort(int* array, int length) {
    for (int i = 1; i < length; i++) {
        int j = i;
        while (j > 0 && array[j-1] > array[j]) {
            int temp = array[j-1];
            array[j-1] = array[j];
            array[j] = temp;
            j--;
        }
    }
    return array;
}

int main() {
    int len = 5;
    int arr[5] = {7, 39, 1, 92, 0};
    int* res = insertionSort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d\n", res[i]);
    }
}
