#include <stdio.h>

//insertion
void insert(int arr[], int *n, int pos, int val) {
  
    // Shift elements to the right
    for (int i = *n; i > pos; i--)
        arr[i] = arr[i - 1];

    // Insert val at the specified position
    arr[pos] = val;

    // Increase the current size
    (*n)++;
}

//deletion
void del(int arr[], int *n, int key) {
  
  	// Find the element
  	int i = 0;
  	while (arr[i] != key) i++;
  	
    // Shifting the right side elements one
  	// position towards left
    for (int j = i; j < *n - 1; j++) {
        arr[j] = arr[j + 1];
    }
  
  	// Decrease the size
    (*n)--; 
}

int main() {
    int arr[5] = {2, 4, 8, 12, 16};
    
    // Print each element of
    // array using loop
    printf("Printing Array Elements\n"); 
    for(int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    printf("\n"); 
    
    // Printing array element in reverse
    printf("Printing Array Elements in Reverse\n"); 
    for(int i = 4; i>=0; i--){
        printf("%d ", arr[i]);
    }
    
    return 0;
}