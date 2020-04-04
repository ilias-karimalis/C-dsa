#include <stdio.h>

void merge(int* arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int a1[n1], a2[n2];

    for (i = 0; i < n1; i++) {
        a1[i] = arr[l+i];
    }

    for (j = 0; j < n2; j++) {
        a2[j] = arr[m + 1 + j];
    }

    i = j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (a1[i] <= a2[j]) {
            arr[k] = a1[i];
            i++;
        } else {
            arr[k] = a2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = a1[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = a2[j];
        j++;
        k++;
    }
}

void mergeSort(int* arr, int l, int r) {
    if (l < r) {
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int len = 5;
    int arr[5] = {7, 39, 1, 92, 0};
    mergeSort(arr, 0, 5);
    for (int i = 0; i < len; i++) {
        printf("%d\n", arr[i]);
    }
}
