#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int queue[SIZE];
int frontA = -1, rearA = -1;

int isEmptyArray() { return (frontA == -1 || frontA > rearA); }
int isFullArray() { return (rearA == SIZE - 1); }

//for linked lists
struct Node {
int data;
struct Node* next;
};
struct Node* frontL = NULL;
struct Node* rearL = NULL;

int isEmptyLinkedList() { return (frontL == NULL); }

int main() {
printf("Array Queue Empty? %s\n", isEmptyArray() ? "Yes" : "No");
rearA = SIZE - 1;
printf("Array Queue Full? %s\n", isFullArray() ? "Yes" : "No");

printf("Linked List Queue Empty? %s\n", isEmptyLinkedList() ? "Yes" : "No");
return 0;
}
