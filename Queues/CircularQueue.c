#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 10
int q[max];
int front=-1;
int rear=-1;
int main(){
    int choice, val;

    while (1) {
        printf("1. Display the queue elements\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
        printf("4. Print size\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5)
            break;

        switch (choice) {
            case 1:
                display();
                break;
            case 2:
                printf("Enter the element you want to add: ");
                scanf("%d", &val);
                Enqueue(val);
                break;
            case 3:
                Dequeue();
                break;
            case 4:
                printf("The size of the queue is %d\n", size());
                break;
            default:
                printf("Wrong choice\n");
        }
    }

    return 0;
}
bool isFull(){
    return (rear+1)%max==front;
}
bool isEmpty(){

    return rear==front;
}
void Enqueue(int val){
    if(isFull()){
        printf("the queue is full\n");
        return;
    }
    if(rear==-1) rear=0;
    rear=(rear+1)%max;
    q[rear]=val;
}
int Dequeue(){
    if(isEmpty()){
        printf("the queue is Empty\n");
        exit(1);
    }
    int delete=q[front];
    front=(front+1)%max;
    return delete;
}
void display() {
    if (isEmpty()) {
        printf("The queue is empty\n");
        return;
    }
    printf("The queue is: ");
    for (int i = front; i != rear; i = (i + 1) % max) {
        printf("%d ", q[i]);
    }
    printf("%d\n", q[rear]);
}
int size() {
    if (isEmpty()) {
        return 0;
    }
    if (rear >= front) {
        return rear - front + 1;
    } else {
        return max - front + rear + 1;
    }
}

