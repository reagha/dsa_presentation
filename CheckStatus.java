public class CheckStatus {
static int SIZE = 5;
static int[] queue = new int[SIZE];
static int frontA = -1, rearA = -1;

static boolean isEmptyArray() { return (frontA == -1 || frontA > rearA); }
static boolean isFullArray() { return (rearA == SIZE - 1); }

//for linked lists
static class Node {
    int data; Node next;
    Node(int val) { data = val; }
}
static Node frontL = null, rearL = null;

static boolean isEmptyLinkedList() { return (frontL == null); }

public static void main(String[] args) {
    System.out.println("Array Queue Empty? " + (isEmptyArray() ? "Yes" : "No"));
    rearA = SIZE - 1;
    System.out.println("Array Queue Full? " + (isFullArray() ? "Yes" : "No"));
    System.out.println("Linked List Queue Empty? " + (isEmptyLinkedList() ? "Yes" : "No"));
}
}
