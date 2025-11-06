#include <stdio.h>
int main() {
    int arr[2][5] = {{10, 20, 30, 40, 50}, {60, 70, 80, 90, 100}};

    printf("Base address of arr: %p\n", arr); // Base address of array

    printf("2D Array Traversal:\n");
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            printf("arr[%d][%d] = %d at address %p\n", i, j, arr[i][j], &arr[i][j]);
        }
    }
}

















































    
 