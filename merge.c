#include <stdio.h>

int main() {
    int arr1[] = {3, 9, 7, 1};
    int arr2[] = {5, 6, 4};
    int size1 = 4, size2 = 3;
    int merged[size1 + size2];
    int i, j;

    // Copy arr1 into merged
    for (i = 0; i < size1; i++) {
        merged[i] = arr1[i];+
    }

    // Copy arr2 into merged after arr1
    for (j = 0; j < size2; j++) {
        merged[size1 + j] = arr2[j];
    }

    // Sort merged array using insertion sort (ascending)
    for (int k = 1; k < size1 + size2; k++) {
        int key = merged[k];
        int m = k - 1;
        while (m >= 0 && merged[m] > key) {
            merged[m + 1] = merged[m];
            m--;
        }
        merged[m + 1] = key;
    }

    // Print merged array (sorted)
    printf("Merged Array (sorted): ");
    for (i = 0; i < size1 + size2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}