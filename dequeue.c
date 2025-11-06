#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int queue[SIZE] = {10, 20, 30};
int frontA = 0, rearA = 2;

void dequeueArray() {
if (frontA == -1 || frontA > rearA)
printf("Array Queue is EMPTY!\n");
else
printf("Dequeued (Array): %d\n", queue[frontA++]);
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

void dequeueLinkedList() {
if (frontL == NULL)
printf("Linked List Queue is EMPTY!\n");
else {
printf("Dequeued (Linked List): %d\n", frontL->data);
struct Node* temp = frontL;
frontL = frontL->next;
free(temp);
if (frontL == NULL) rearL = NULL;
}
}

int main() {
enqueueL(10);
enqueueL(20);
dequeueArray();
dequeueLinkedList();
return 0;
}
