public class display {
static int[] queue = {10, 20, 30};
static int frontA = 0, rearA = 2;

static void displayArray() {
    if (frontA == -1 || frontA > rearA)
        System.out.println("Array Queue is EMPTY!");
    else {
        System.out.print("Array Queue: ");
        for (int i = frontA; i <= rearA; i++)
            System.out.print(queue[i] + " ");
        System.out.println();
    }
}

//for linked lists
static class Node {
    int data; Node next;
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

static void displayLinkedList() {
    if (frontL == null)
        System.out.println("Linked List Queue is EMPTY!");
    else {
        System.out.print("Linked List Queue: ");
        Node temp = frontL;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}

public static void main(String[] args) {
    enqueueL(10);
    enqueueL(20);
    enqueueL(30);
    displayArray();
    displayLinkedList();
}
}
