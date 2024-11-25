#include<stdio.h>
#include<stdlib.h>
#define max 10
int stack[max];
int top=-1;
void push(int value);
void pop();
void display();
int main(){
    int choice,data;
    while(1){
        printf("1.pop\n");
        printf("2.push\n");
        printf("3.Display\n");
        printf("4.Quit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        if(choice == 4) break;
        switch(choice){
            case 1:
            pop();
            break;
            case 2:
            printf("enter the element you want to push:\n");
            scanf("%d",&data);
            push(data);
            break;
            case 3:
            display();
            break;
            default:
            printf("wrong choice \n");
            break;
        }
    }
}
void push(int value){
 if(top == max - 1){
    printf("stack is full\n");
    return;
 }
 top = top + 1;
 stack[top] = value;
}
void pop(){
    if(top == -1){
        printf("stack is empty\n");
        return;
    }
    int deleted = stack[top];
    top = top - 1;
    printf("the popped element is : %d\n",deleted);
}
void display(){
   if(top == -1){
        printf("stack is empty\n");
        return;
    }
    printf("the stack is\n");
    for(int i = top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}
