#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 10
int queue[max];
int rear = -1;
int front = -1;
bool isEmpty();
bool isFull();
void enqueue(int value);
int dequeue();
void display();
int main(){
    int choice,data;
    while(1){
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Quit\n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        if(choice == 4) break;
        switch(choice){
            case 1:
            printf("enter the value you want to enqueue\n");
            scanf("%d",&data);
            enqueue(data);
            break;
            case 2:
            if(dequeue() == -1) printf("the queue is empty \n");
            else{
                printf("the deleted element is : %d\n",dequeue());
            }
            break;
            case 3:
            display();
            break;
            default:
            printf("wrong choice\n");
        }
    }
}
bool isEmpty(){
    return rear == front;
}
bool isFull(){
    return (rear + 1) % max == front;
}
void enqueue(int value){
    if(isFull()){
        printf("the queue is full\n");
        return;
    }
    if(isEmpty()){
        front = 0;
    }
    rear = (rear + 1) % max;
    queue[rear] = value;
}
int dequeue(){
    if(isEmpty()){
        return -1;
    }
    if(rear == front){
        rear = -1;
        front = -1;
    }
    else{
        int deleted = queue[front];
        front = (front + 1) % max;
    }
    return deleted;
}
void display(){
    if(isEmpty()){
        printf("the queue is empty\n");
        return;
    }
    printf("the queue is : \n");
    for(int i=front ;i!=rear ; i=(i+1)%max){
        printf("%d\n",queue[i]);
    }
    printf("%d\n",queue[rear]);
}
