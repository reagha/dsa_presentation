#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void producerEnqueue(int id, int value) {
    if (rear == SIZE - 1)
    printf("Producer %d: Queue FULL!\n", id);
    else {
        if (front == -1) front = 0;
        queue[++rear] = value;
        printf("Producer %d added: %d\n", id, value);
    }
}

void consumerDequeue() {
    if (front == -1 || front > rear)
    printf("Consumer: Queue EMPTY!\n");
    else
    printf("Consumer processed: %d\n", queue[front++]);
}

int main() {
    producerEnqueue(1, 10);
    producerEnqueue(2, 20);
    producerEnqueue(3, 30);
    consumerDequeue();
    consumerDequeue();
return 0;
}
