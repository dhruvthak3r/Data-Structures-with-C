#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int val;
    struct node *next;
};
void push(int value);
int pop();
int peek();
void display();
struct node *head=NULL;
int main(){
    int choice,data;
    while(1){
        printf("1.Display the stack : \n");
        printf("2.Push an element into the stack : \n");
        printf("3.Pop an element from the stack : \n");
        printf("4.return the top element from the stack : \n");
        printf("5.Quit : \n");
        printf("enter your choice : \n");
        scanf("%d",&choice);
        if(choice==5) break;
        switch(choice){
            case 1:
            display();
            break;
            case 2:
            printf("enter the element you want to push :\n");
            scanf("%d",&data);
            push(data);
            break;
            case 3:
            printf("the popped element is : %d",pop());
            break;
            case 4:
            printf("the top element from the stack is : %d",peek());
            break;
            default:
            printf("Wrong Chocie\n");
            break;
        }
    }
}
void push(int value){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    if(head==NULL){
        head=newnode;
        return;
    }
    newnode->val=value;
    newnode->next=head;
    head=newnode;
}
int pop(){
    if(head==NULL){
        printf("the stack is empty\n");
        exit(1);
    }
    int pop=head->val;
    head=head->next;
}
int peek(){
    if(head==NULL){
        printf("the stack is empty\n");
        exit(1);
    }
    return head->val;
}
void display(){
    if(head==NULL){
        printf("the stack is empty\n");
        return;
    }
    struct node *temp=head;
    printf("the elements of stack are : \n");
    while(temp!=NULL){
        printf("%d\n",temp->val);
        temp=temp->next;
    }
}