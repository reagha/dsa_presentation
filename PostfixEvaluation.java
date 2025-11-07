import java.util.Stack;

public class PostfixEvaluation {

    // Method to evaluate postfix expression
    static int evaluatePostfix(String exp) {
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < exp.length(); i++) {
            char ch = exp.charAt(i);

            // If character is a digit, push it as integer
            if (Character.isDigit(ch)) {
                stack.push(ch - '0');  // Convert char digit to int
            }

            // If operator, pop two values and apply operation
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                int val2 = stack.pop();
                int val1 = stack.pop();
                int result = 0;

                switch (ch) {
                    case '+': result = val1 + val2; break;
                    case '-': result = val1 - val2; break;
                    case '*': result = val1 * val2; break;
                    case '/': result = val1 / val2; break;
                }
                stack.push(result); // push the result
            }
        }
        return stack.pop(); // Final result
    }

    public static void main(String[] args) {
        String exp = "234*+5-"; // Example expression
        System.out.println("Postfix Expression: " + exp);
        System.out.println("Evaluated Result: " + evaluatePostfix(exp));
    }
}
