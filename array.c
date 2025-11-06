#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    printf("Base address of arr: %p\n", arr); // Base address of array

    printf("1D Array Traversal:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d at address %p\n", i, arr[i], &arr[i]);
    }

    return 0;
}


















