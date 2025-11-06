#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int queue[SIZE] = {10, 20, 30};
int frontA = 0, rearA = 2;

void displayArray() {
if (frontA == -1 || frontA > rearA)
printf("Array Queue is EMPTY!\n");
else {
printf("Array Queue: ");
for (int i = frontA; i <= rearA; i++)
printf("%d ", queue[i]);
printf("\n");
}
}

//for linked lists
struct Node {
int data;
struct Node* next;
};
struct Node* frontL = NULL;
struct Node* rearL = NULL;

void enqueueL(int value) {
struct Node* newNode = malloc(sizeof(struct Node));
newNode->data = value;
newNode->next = NULL;
if (rearL == NULL)
frontL = rearL = newNode;
else {
rearL->next = newNode;
rearL = newNode;
}
}

void displayLinkedList() {
if (frontL == NULL)
printf("Linked List Queue is EMPTY!\n");
else {
printf("Linked List Queue: ");
struct Node* temp = frontL;
while (temp) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}
}

int main() {
enqueueL(10);
enqueueL(20);
enqueueL(30);
displayArray();
displayLinkedList();
return 0;
}
