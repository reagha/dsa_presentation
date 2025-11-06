#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front)
    printf("Queue is FULL!\n");
    else {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

void dequeue() {
    if (front == -1)
    printf("Queue is EMPTY!\n");
    else {
        printf("Dequeued: %d\n", queue[front]);
        if (front == rear)
        front = rear = -1;
        else
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1)
    printf("Queue is EMPTY!\n");
    else {
        printf("Circular Queue: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
enqueue(1);
enqueue(2);
enqueue(3);
dequeue();
enqueue(4);
enqueue(5);
enqueue(6); // test full
display();
return 0;
}
