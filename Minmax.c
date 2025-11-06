#include <stdio.h>

#define ROW 3
#define COL 3

// Function to find minimum element
void findMin(int arr[ROW][COL]) {
    int min = arr[0][0];
    int row = 0, col = 0;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (arr[i][j] < min) {
                min = arr[i][j];
                row = i;
                col = j;
            }
        }
    }
    printf("Minimum = %d at location (%d,%d)\n", min, row, col);
}

// Function to find maximum element
void findMax(int arr[ROW][COL]) {
    int max = arr[0][0];
    int row = 0, col = 0;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
                row = i;
                col = j;
            }
        }
    }
    printf("Maximum = %d at location (%d,%d)\n", max, row, col);
}

int main() {
    int arr[ROW][COL] = {
        {4, 8, 3},
        {9, 1, 7},
        {6, 5, 2}
    };

    findMin(arr);
    findMax(arr);

    return 0;
}