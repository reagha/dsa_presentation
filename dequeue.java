public class dequeue {
//for arrays
static int[] queue = {10, 20, 30};
static int frontA = 0, rearA = 2;

static void dequeueArray() {
    if (frontA == -1 || frontA > rearA)
        System.out.println("Array Queue is EMPTY!");
    else
        System.out.println("Dequeued (Array): " + queue[frontA++]);
}

//for linked lists
static class Node {
    int data;
    Node next;
    Node(int val) { data = val; }
}
static Node frontL = null, rearL = null;

static void enqueueL(int value) {
    Node newNode = new Node(value);
    if (rearL == null)
        frontL = rearL = newNode;
    else {
        rearL.next = newNode;
        rearL = newNode;
    }
}

static void dequeueLinkedList() {
    if (frontL == null)
        System.out.println("Linked List Queue is EMPTY!");
    else {
        System.out.println("Dequeued (Linked List): " + frontL.data);
        frontL = frontL.next;
        if (frontL == null) rearL = null;
    }
}

public static void main(String[] args) {
    enqueueL(10);
    enqueueL(20);
    dequeueArray();
    dequeueLinkedList();
}
}
