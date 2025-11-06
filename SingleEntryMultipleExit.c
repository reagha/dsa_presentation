#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1)
    printf("Queue is FULL!\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = value;
        printf("Producer added: %d\n", value);
    }
}

void consumerDequeue(int id) {
    if (front == -1 || front > rear)
    printf("Consumer %d: Queue EMPTY!\n", id);
    else
    printf("Consumer %d removed: %d\n", id, queue[front++]);
}

int main() {
enqueue(4);
enqueue(5);
enqueue(6);
consumerDequeue(1);
consumerDequeue(2);
consumerDequeue(3);
consumerDequeue(4);
return 0;
}
