#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define max 100

char stack[max];
int top = -1;
char infix[max];
char postfix[max];

bool isFull();
bool isEmpty();
void push(char symbol);
char pop();
void infixtopostfix();
char peek();
int precedence(char symbol);
int evaluatePostfix();

int main() {
    printf("Enter the infix expression:\n");
    fgets(infix, max, stdin);
    infixtopostfix();
    printf("The postfix expression is: %s\n", postfix);
    printf("The result of the postfix evaluation is: %d\n", evaluatePostfix());
    return 0;
}

bool isFull() {
    return top == max - 1;
}

bool isEmpty() {
    return top == -1;
}

void push(char symbol) {
    if (isFull()) {
        printf("The stack is full\n");
        exit(1);
    }
    stack[++top] = symbol;
}

char pop() {
    if (isEmpty()) {
        printf("The stack is empty\n");
        exit(1);
    }
    return stack[top--];
}

void infixtopostfix() {
    int index = 0;
    for (int i = 0; i < strlen(infix); i++) {
        char curr = infix[i];
        if (curr == ' ' || curr == '\n') continue;
        if (isdigit(curr)) {
            postfix[index++] = curr;
        } else {
            switch (curr) {
                case '(':
                    push(curr);
                    break;
                case ')':
                    while (!isEmpty() && peek() != '(') {
                        postfix[index++] = pop();
                    }
                    pop();
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':
                    while (!isEmpty() && precedence(peek()) >= precedence(curr)) {
                        postfix[index++] = pop();
                    }
                    push(curr);
                    break;
                default:
                    printf("Invalid character encountered\n");
                    exit(1);
            }
        }
    }
    while (!isEmpty()) {
        postfix[index++] = pop();
    }
    postfix[index] = '\0';
}

char peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack[top];
}

int precedence(char symbol) {
    switch (symbol) {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int evaluatePostfix() {
    int evalStack[max];
    int evalTop = -1;
    for (int i = 0; i < strlen(postfix); i++) {
        char curr = postfix[i];
        if (isdigit(curr)) {
            evalStack[++evalTop] = curr - '0';
        } else {
            int val2 = evalStack[evalTop--];
            int val1 = evalStack[evalTop--];
            switch (curr) {
                case '+':
                    evalStack[++evalTop] = val1 + val2;
                    break;
                case '-':
                    evalStack[++evalTop] = val1 - val2;
                    break;
                case '*':
                    evalStack[++evalTop] = val1 * val2;
                    break;
                case '/':
                    evalStack[++evalTop] = val1 / val2;
                    break;
                case '%':
                    evalStack[++evalTop] = val1 % val2;
                    break;
                case '^':
                    evalStack[++evalTop] = (int)pow(val1, val2);
                    break;
                default:
                    printf("Invalid operator encountered\n");
                    exit(1);
            }
        }
    }
    return evalStack[evalTop];
}
