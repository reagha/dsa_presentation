#include <stdio.h>
#define MAX 5   // Maximum size of the stack

// Declare stack and top pointer
int stack[MAX];
int top = -1;   // Stack is initially empty

// Function to push an element into the stack
void push(int x) {
    if (top == MAX - 1) { // Check if stack is full
        printf("Stack Overflow! Cannot push %d\n", x);
    } else {
        stack[++top] = x; // Increment top and insert the element
        printf("%d pushed to stack\n", x);
    }
}

// Function to pop (remove) the top element
void pop() {
    if (top == -1) { // Check if stack is empty
        printf("Stack Underflow! Nothing to pop\n");
    } else {
        printf("%d popped from stack\n", stack[top--]); // Print and remove top element
    }
}

// Function to view the top element without removing it
void peek() {
    if (top == -1)
        printf("Stack is empty!\n");
    else
        printf("Top element: %d\n", stack[top]);
}

// Function to display all elements in the stack
void display() {
    if (top == -1)
        printf("Stack is empty!\n");
    else {
        printf("Stack elements (top to bottom): ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

// Main function to test stack operations
int main() {
    push(10);   // Add 10
    push(20);   // Add 20
    push(30);   // Add 30
    display();  // Show stack content
    peek();     // Show top element
    pop();      // Remove top element
    display();  // Show stack after popping
    return 0;
}
