#include <stdio.h>

int* selectionSort(int* array, int length) {
    for (int i = 0; i < length - 1; i++) {
        int jMin = i;
        for (int j = i + 1; j < length; j++) {
            if (array[j] < array[jMin]) {
                jMin = j;
            }
        }
        if (jMin != i) {
            int temp = array[i];
            array[i] = array[jMin];
            array[jMin] = temp;
        }
    }
    return array;
}

int main() {
    int len = 5;
    int arr[5] = {7, 39, 1, 92, 0};
    int* res = selectionSort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d\n", res[i]);
    }
}
