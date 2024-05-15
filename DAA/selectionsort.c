#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int arr[50], n;


void SelectionSort() {
    int min, t;
    for (int i = 0; i < (n - 1); i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        t = arr[i];
        arr[i] = arr[min];
        arr[min] = t;
    }
}


int main() {
    clock_t start, end;

    printf("Enter the number of elements of the array: ");
    scanf("%d", &n);
    // printf("The array to be sorted:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
        // printf("%d ", arr[i]);
    }

    start = clock();
    SelectionSort(arr, n);
    end = clock();

    printf("\nSorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    double time_taken = difftime(end, start) / (double)CLOCKS_PER_SEC;
    printf("\nTime taken for sorting: %.2lf seconds\n", time_taken);

    return 0;
}
