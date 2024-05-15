#include <stdio.h>

int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void binarysearch(int low, int high, int key) {
    if (low > high) {
        printf("element not found in given array\n");
        return;
    }

    int mid = low + (high - low) / 2;

    if (key == A[mid]) {
        printf("element found at index %d\n", mid);
        return;
    } else if (key > A[mid]) {
        binarysearch(mid + 1, high, key);
    } else {
        binarysearch(low, mid - 1, key);
    }
}

int main() {
    int ele;
    printf("enter a number to be found in array: ");
    scanf("%d", &ele);
    binarysearch(0, sizeof(A) / sizeof(A[0]) - 1, ele);
    return 0;
}
