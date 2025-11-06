#include <stdio.h>
#include <ctype.h>  // For isdigit()
#define MAX 100

int stack[MAX];
int top = -1;

// Function to push value onto stack
void push(int x) {
    stack[++top] = x;
}

// Function to pop value from stack
int pop() {
    return stack[top--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char *exp) {
    int i = 0;
    while (exp[i] != '\0') {
        char ch = exp[i];

        // If the character is a digit, push it
        if (isdigit(ch)) {
            push(ch - '0'); // convert char to int
        }

        // If the character is an operator, pop 2 operands and apply the operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int val2 = pop();  // second operand
            int val1 = pop();  // first operand
            int result;

            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }
            push(result); // push result back
        }
        i++;
    }
    return pop(); // Final result on top of stack
}

int main() {
    char exp[] = "234*+5-";  // Postfix expression
    printf("Postfix Expression: %s\n", exp);
    printf("Evaluated Result: %d\n", evaluatePostfix(exp));
    return 0;
}
