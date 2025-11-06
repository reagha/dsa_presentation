public class enqueue {
//for arrays
static int SIZE = 5;
static int[] queueA = new int[SIZE];
static int frontA = -1, rearA = -1;

static void enqueueArray(int value) {
    if (rearA == SIZE - 1) {
        System.out.println("Array Queue is FULL!");
        return;
    }
    if (frontA == -1) frontA = 0;
    queueA[++rearA] = value;
    System.out.println("Enqueued (Array): " + value);
}

//for linked lists
static class Node {
    int data;
    Node next;
    Node(int val) { data = val; next = null; }
}

static Node frontL = null, rearL = null;

static void enqueueLinkedList(int value) {
    Node newNode = new Node(value);
    if (rearL == null)
        frontL = rearL = newNode;
    else {
        rearL.next = newNode;
        rearL = newNode;
    }
    System.out.println("Enqueued (Linked List): " + value);
}

public static void main(String[] args) {
    System.out.println("Using Array Queue:");
    enqueueArray(10);
    enqueueArray(20);
    enqueueArray(30);
    enqueueArray(40);
    enqueueArray(50);
    enqueueArray(60); // This should trigger "Array Queue is FULL!"

    System.out.println("\nUsing Linked List Queue:");
    enqueueLinkedList(30);
    enqueueLinkedList(40);
    enqueueLinkedList(50);
    enqueueLinkedList(60);
}
}
