#include <stdio.h>
#define SIZE 5

struct Item {
    int value;
    int priority;
};

struct Item pq[SIZE];
int count = 0;

void enqueue(int value, int priority) {
    if (count == SIZE)
    printf("Priority Queue is FULL!\n");
    else {
        pq[count].value = value;
        pq[count].priority = priority;
        count++;
        printf("Enqueued: %d (priority %d)\n", value, priority);
    }
}

void dequeue() {
    if (count == 0) {
        printf("Queue is EMPTY!\n");
        return;
    }
    int highest = 0;
    for (int i = 1; i < count; i++) {
        if (pq[i].priority > pq[highest].priority)
        highest = i;
    }
    printf("Dequeued: %d (priority %d)\n", pq[highest].value, pq[highest].priority);
    for (int i = highest; i < count - 1; i++)
    pq[i] = pq[i + 1];
    count--;
}

void display() {
    if (count == 0)
    printf("Queue is EMPTY!\n");
    else {
        printf("Priority Queue: ");
        for (int i = 0; i < count; i++)
        printf("[%d|%d] ", pq[i].value, pq[i].priority);
        printf("\n");
    }
}

int main() {
enqueue(4, 2);
enqueue(8, 1);
enqueue(9, 3);
dequeue();
display();
return 0;
}
