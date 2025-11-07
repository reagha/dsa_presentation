#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// --- Stack for characters ---
char stack[MAX];
int top = -1;

// Push character to stack
void push(char c) {
    stack[++top] = c;
}

// Pop character from stack
char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

// Peek top of stack
char peek() {
    if (top == -1)
        return -1;
    return stack[top];
}

// Return precedence value of an operator
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// --- Convert INFIX → POSTFIX ---
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        // If operand, add to output
        if (isalnum(c))
            postfix[j++] = c;

        // If '(', push to stack
        else if (c == '(')
            push(c);

        // If ')', pop until '('
        else if (c == ')') {
            while (peek() != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        }

        // If operator
        else {
            while (precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    // Pop remaining operators
    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0'; // end string
}

// --- Reverse a string (used for prefix) ---
void reverse(char *exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

// --- Convert INFIX → PREFIX ---
void infixToPrefix(char infix[], char prefix[]) {
    char revInfix[MAX], revPostfix[MAX];
    strcpy(revInfix, infix);

    // Step 1: Reverse the infix
    reverse(revInfix);

    // Step 2: Swap brackets
    for (int i = 0; i < strlen(revInfix); i++) {
        if (revInfix[i] == '(')
            revInfix[i] = ')';
        else if (revInfix[i] == ')')
            revInfix[i] = '(';
    }

    // Step 3: Get postfix of reversed infix
    top = -1;
    infixToPostfix(revInfix, revPostfix);

    // Step 4: Reverse postfix to get prefix
    reverse(revPostfix);
    strcpy(prefix, revPostfix);
}

// --- Evaluate POSTFIX expression ---
int evaluatePostfix(char postfix[]) {
    int evalStack[MAX];
    int evalTop = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        // If digit, push integer value
        if (isdigit(c)) {
            evalStack[++evalTop] = c - '0';
        }
        // If operator, pop 2 operands and apply
        else {
            int val2 = evalStack[evalTop--];
            int val1 = evalStack[evalTop--];
            int result = 0;

            switch (c) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }
            evalStack[++evalTop] = result;
        }
    }
    return evalStack[evalTop];
}

// --- MAIN PROGRAM ---
int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];

    printf("Enter infix expression (e.g. (2+3)*4 ): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);

    printf("\nPostfix Expression: %s", postfix);
    printf("\nPrefix Expression: %s", prefix);

    // Only works for numeric postfix expressions
    printf("\nEvaluated Postfix Result: %d\n", evaluatePostfix(postfix));

    return 0;
}
