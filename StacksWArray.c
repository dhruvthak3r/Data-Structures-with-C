#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define max 5
int stack[max];
int top=-1;
bool isfull();
bool isempty();
void push(int element);
int pop();
int peek();
void display();
int main(){
    int choice,data;
    while(1){
        printf("1.push an element onto the stack\n");
        printf("2.pop an element from the stack\n");
        printf("3.retrieve the top element of the stack\n");
        printf("4.display stack");
        printf("5.Quit\n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        if(choice==5) break;
        switch(choice){
            case 1:
            printf("enter the element you want to push\n");
            scanf("%d",&data);
            push(data);
            break;
            case 2:
            printf("the popped element is %d\n",pop());
            break;
            case 3:
            printf("the element at the top of the stack is\n",peek());
            break;
            case 4:
            display();
            break;
            default:
            printf("wrong choice\n");
            break;
        }
    }
}
bool isfull(){
    if(top==max-1) return true;
    return false;
}
bool isempty(){
    if(top==-1) return true;
    return false;
}
void push(int element){
    if(isfull()){
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top]=element;
}
int pop(){
    if(isempty()){
        scanf("Stack is Empty\n");
        exit(1);
    }
    int popped=stack[top];
    top--;
    return popped;
}
int peek(){
    if(isempty()){
        printf("Stack is empty\n");
        exit(1);
    }
    return stack[top];
}
void display(){
    if(isempty()){
        printf("stack is empty\n");
        return;
    }
    printf("the stack is");
    for(int i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}