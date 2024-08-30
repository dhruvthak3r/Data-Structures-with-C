#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define max 100
char stack[max];
bool isEmpty();
bool isFull();
void infixtopostfix(char infix[],char postfix[]);
void push(char symbol);
char peek();
char pop();
int precedence(char symbol);
int top=-1;

int main(){
    char infix[max],postfix[max];
    printf("Enter infix expression:\n");
    fgets(infix, max, stdin);
    infixtopostfix(infix, postfix);
    printf("Postfix expression is: %s\n", postfix);
}

bool isFull(){
    return top == max - 1;
}

bool isEmpty(){
    return top == -1;
}

void infixtopostfix(char infix[], char postfix[]){
    char symbol;
    int index = 0;
    for(int i = 0; i < strlen(infix); i++){
        symbol = infix[i];
        switch(symbol){
            case '(':
                push(symbol);
                break;
            case ')':
                while(!isEmpty() && peek() != '('){
                    postfix[index++] = pop();
                }
                pop(); // Remove '(' from stack
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while(!isEmpty() && precedence(stack[top]) >= precedence(symbol)){
                    postfix[index++] = pop();
                }
                push(symbol);
                break;
            default:
                postfix[index++] = symbol;
        }
    }
    while(!isEmpty()){
        postfix[index++] = pop();
    }
    postfix[index] = '\0';
}

void push(char symbol){
    if(isFull()){
        printf("Stack is full\n");
        return;
    }
    stack[++top] = symbol;
}

char pop(){
    if(isEmpty()){
        printf("Stack is empty\n");
        exit(1);
    }
    return stack[top--];
}

char peek(){
    if(isEmpty()){
        printf("Stack is empty\n");
        exit(1);
    }
    return stack[top];
}

int precedence(char symbol){
    switch(symbol){
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;
        case '^': return 3;
        default: return 0;
    }
}
