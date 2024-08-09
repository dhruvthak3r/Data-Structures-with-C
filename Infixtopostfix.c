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
int top=0;
int main(){
    char infix[max],postfix[max];
    printf("enter infix impression\n");
    gets(infix);
    infixtopostfix(infix, postfix);
	printf("Postfix expression is : %s\n",postfix);
}
bool isFull(){
    if(top==max-1) return true;
    return false;
}
bool isEmpty(){
    if(top==0) return true;
    return false;
}
void infixtopostfix(char infix[],char postfix[]){
    char next,symbol;
    int index=0;
    for(int i=0;i<strlen(infix);i++){
        switch(symbol){
            case '(':
            push(symbol);
            break;
            case ')':
            while(!isEmpty()&&peek()!='('){
                char next=pop();
                postfix[index++]=next;
            }
            break;
            case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
				while( !isEmpty() &&  precedence(stack[top])>= precedence(symbol) )
					postfix[index++]=pop();
				push(symbol);
				break;
                default:
			     postfix[index++]=symbol;
        }
        while(!isEmpty()) 
		postfix[index++]=pop();
	postfix[index]='\0';
    }
}
void push(char symbol){
    if(isFull()){
        printf("stack is full\n");
        return;
    }
    stack[top++]=symbol;
}
char pop(){
    if(isEmpty()){
        printf("stack is empty\n");
        exit(1);
    }
    char popped=stack[top];
    top--;
    return popped;
}
char peek(){
    if(isEmpty()){
        printf("the stack is empty\n");
        exit(1);
    }
    return stack[top];
}
int precedence(char symbol){
    if(symbol=='(') return 0;
    if(symbol=='+'||symbol=='-') return 1;
    if(symbol=='*'||symbol=='/'||symbol=='%') return 2;
    if(symbol=='^') return 3;
    return 0;
}

