#include <stdio.h>
#define SIZE 6

int queue[SIZE];
int front = -1, rear = -1;

void producer(int id, int value) {
    if (rear == SIZE - 1)
    printf("Producer %d: Queue FULL!\n", id);
    else {
        if (front == -1) front = 0;
        queue[++rear] = value;
        printf("Producer %d added: %d\n", id, value);
    }
}

void consumer(int id) {
    if (front == -1 || front > rear)
    printf("Consumer %d: Queue EMPTY!\n", id);
    else
    printf("Consumer %d removed: %d\n", id, queue[front++]);
}

int main() {
    producer(1, 10);
    producer(2, 20);
    producer(3, 30);
    consumer(1);
    consumer(2);
    producer(4, 40);
    consumer(3);
    consumer(4);
    return 0;
}