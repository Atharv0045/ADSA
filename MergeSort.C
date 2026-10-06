#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

void main() {
    int arr[10];
    int i;
    clrscr();

    randomize();

    printf("Original Array:\n");
    for (i = 0; i < 10; i++) {
        arr[i] = rand() % 100 + 1;
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    mergeSort(arr, 0, 9);

    printf("Sorted Array:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    getch();
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArray[20];
    int rightArray[20];

    for (i = 0; i < n1; i++) {
        leftArray[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        rightArray[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}
