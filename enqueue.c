#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

//for arrays
int queue[SIZE];
int front_arr = -1, rear_arr = -1;

void enqueue_array(int value) {
    if (rear_arr == SIZE - 1) {
        printf("Queue is full! %d\n", value);
    } else {
        if (front_arr == -1) front_arr = 0;
        queue[++rear_arr] = value;
        printf("Added %d to array queue.\n", value);
    }
}

//for linked lists
struct Node {
    int data;
    struct Node* next;
};

struct Node* front_list = NULL;
struct Node* rear_list = NULL;

void enqueue_list(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear_list == NULL) {
        front_list = rear_list = newNode;
    } else {
        rear_list->next = newNode;
        rear_list = newNode;
    }
    printf("%d enqueued into linked list queue.\n", value);
}

int main() {
    printf("in arrays.\n");
    enqueue_array(10);
    enqueue_array(20);
    enqueue_array(30);
    printf("in linked lists.\n");
    enqueue_list(3);
    enqueue_list(2);
    enqueue_list(1);
    return 0;
}
