public class Stacklinkedlist {

    // Inner class to represent a node in linked list
    class Node {
        int data;    // Value stored in node
        Node next;   // Reference to next node

        Node(int d) { // Constructor
            data = d;
            next = null;
        }
    }

    private Node top = null; // Initially, stack is empty

    // Push method: insert at top
    void push(int x) {
        Node newNode = new Node(x); // Create new node
        newNode.next = top;         // New node points to current top
        top = newNode;              // Move top to new node
        System.out.println(x + " pushed to stack");
    }

    // Pop method: remove top element
    void pop() {
        if (top == null) // Check if stack is empty
            System.out.println("Stack Underflow! Nothing to pop");
        else {
            System.out.println(top.data + " popped from stack");
            top = top.next; // Move top to next node
        }
    }

    // Peek method: view top element
    void peek() {
        if (top == null)
            System.out.println("Stack is empty!");
        else
            System.out.println("Top element: " + top.data);
    }

    // Display method: print all elements
    void display() {
        if (top == null)
            System.out.println("Stack is empty!");
        else {
            System.out.print("Stack elements (top to bottom): ");
            Node temp = top;
            while (temp != null) {
                System.out.print(temp.data + " ");
                temp = temp.next;
            }
            System.out.println();
        }
    }

    // Main method to test
    public static void main(String[] args) {
        Stacklinkedlist s = new Stacklinkedlist();
        s.push(10);
        s.push(20);
        s.push(30);
        s.display();
        s.peek();
        s.pop();
        s.display();
    }
}

    

