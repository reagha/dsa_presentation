class StackArray {
    private int MAX = 5;        // Maximum size of the stack
    private int[] stack = new int[MAX]; // Array to store stack elements
    private int top = -1;       // Stack initially empty

    // Push method to insert an element
    void push(int x) {
        if (top == MAX - 1) // Check if stack is full
            System.out.println("Stack Overflow! Cannot push " + x);
        else
            stack[++top] = x;  // Increment top and insert value
        System.out.println(x + " pushed to stack");
    }

    // Pop method to remove top element
    void pop() {
        if (top == -1) // Check if stack is empty
            System.out.println("Stack Underflow! Nothing to pop");
        else
            System.out.println(stack[top--] + " popped from stack"); // Print and remove
    }

    // Peek method to see the top element
    void peek() {
        if (top == -1)
            System.out.println("Stack is empty!");
        else
            System.out.println("Top element: " + stack[top]);
    }

    // Display all elements
    void display() {
        if (top == -1)
            System.out.println("Stack is empty!");
        else {
            System.out.print("Stack elements (top to bottom): ");
            for (int i = top; i >= 0; i--)
                System.out.print(stack[i] + " ");
            System.out.println();
        }
    }

    // Main method to test
    public static void main(String[] args) {
        StackArray s = new StackArray();
        s.push(10);
        s.push(20);
        s.push(30);
        s.display();
        s.peek();
        s.pop();
        s.display();
    }
}
