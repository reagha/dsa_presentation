import java.util.Stack;
import java.util.Scanner;

public class ExpressionConverter {

    // --- Function to check precedence of operators ---
    static int precedence(char c) {
        if (c == '^')
            return 3;
        else if (c == '*' || c == '/')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return 0;
    }

    // --- Convert Infix → Postfix ---
    static String infixToPostfix(String infix) {
        Stack<Character> stack = new Stack<>();
        StringBuilder postfix = new StringBuilder();

        for (char c : infix.toCharArray()) {

            // If operand, add directly to result
            if (Character.isLetterOrDigit(c)) {
                postfix.append(c);
            }

            // If '(', push to stack
            else if (c == '(') {
                stack.push(c);
            }

            // If ')', pop until '('
            else if (c == ')') {
                while (!stack.isEmpty() && stack.peek() != '(') {
                    postfix.append(stack.pop());
                }
                stack.pop(); // remove '('
            }

            // If operator
            else {
                while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(c)) {
                    postfix.append(stack.pop());
                }
                stack.push(c);
            }
        }

        // Pop remaining operators
        while (!stack.isEmpty()) {
            postfix.append(stack.pop());
        }

        return postfix.toString();
    }

    // --- Reverse a string (used in prefix conversion) ---
    static String reverse(String str) {
        return new StringBuilder(str).reverse().toString();
    }

    // --- Convert Infix → Prefix ---
    static String infixToPrefix(String infix) {
        // Step 1: Reverse infix
        String revInfix = reverse(infix);

        // Step 2: Swap '(' and ')'
        char[] chars = revInfix.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] == '(')
                chars[i] = ')';
            else if (chars[i] == ')')
                chars[i] = '(';
        }
        revInfix = new String(chars);

        // Step 3: Convert reversed infix to postfix
        String revPostfix = infixToPostfix(revInfix);

        // Step 4: Reverse postfix to get prefix
        return reverse(revPostfix);
    }

    // --- Evaluate Postfix Expression ---
    static int evaluatePostfix(String postfix) {
        Stack<Integer> stack = new Stack<>();

        for (char c : postfix.toCharArray()) {
            // If operand (digit), push to stack
            if (Character.isDigit(c)) {
                stack.push(c - '0'); // convert char to int
            }
            // If operator, pop 2 operands and apply operation
            else {
                int val2 = stack.pop();
                int val1 = stack.pop();
                int result = 0;

                switch (c) {
                    case '+': result = val1 + val2; break;
                    case '-': result = val1 - val2; break;
                    case '*': result = val1 * val2; break;
                    case '/': result = val1 / val2; break;
                }
                stack.push(result); // push result back
            }
        }
        // Final answer
        return stack.pop();
    }

    // --- Main Program ---
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Infix Expression (e.g. (2+3)*4 ): ");
        String infix = sc.next();

        // Convert and display
        String postfix = infixToPostfix(infix);
        String prefix = infixToPrefix(infix);

        System.out.println("\nPostfix Expression: " + postfix);
        System.out.println("Prefix Expression: " + prefix);

        // Evaluate postfix (works only for numeric operands)
        System.out.println("Evaluated Postfix Result: " + evaluatePostfix(postfix));
    }
}
