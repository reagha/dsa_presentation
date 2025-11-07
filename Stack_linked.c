#include <stdio.h>
#include <stdlib.h>

// Define structure for each stack node
struct Node {
    int data;            // Value of the node
    struct Node *next;   // Pointer to next node
};

struct Node *top = NULL; // Initialize top pointer to NULL (empty stack)

// Push operation — add element at the top
void push(int x) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = x;      // Set data
    newNode->next = top;    // Point new node to current top
    top = newNode;          // Move top to new node
    printf("%d pushed to stack\n", x);
}

// Pop operation — remove top element
void pop() {
    if (top == NULL) { // Check if stack is empty
        printf("Stack Underflow! Nothing to pop\n");
    } else {
        struct Node *temp = top;  // Store current top node
        printf("%d popped from stack\n", top->data);
        top = top->next;          // Move top to next node
        free(temp);               // Free memory of old top node
    }
}

// Peek operation — show top element
void peek() {
    if (top == NULL)
        printf("Stack is empty!\n");
    else
        printf("Top element: %d\n", top->data);
}

// Display all elements in stack
void display() {
    if (top == NULL)
        printf("Stack is empty!\n");
    else {
        struct Node *temp = top;
        printf("Stack elements (top to bottom): ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function to demonstrate stack
int main() {
    push(10);
    push(20);
    push(30);
    display();
    peek();
    pop();
    display();
    return 0;
}
