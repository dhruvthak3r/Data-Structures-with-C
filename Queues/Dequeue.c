#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 10

int queue[max];
int rear = -1;
int front = -1;

bool isEmpty();
bool isFull();
void enqueue_using_rear(int value);
int dequeue_using_front();
void enqueue_using_front(int value);
int dequeue_using_rear();
void display();

int main(){
    int choice, data, j, c, x;
    while(1){
        printf("1. Input-Restricted\n");
        printf("2. Output-Restricted\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice == 4) break;
        switch(choice){
            case 1:
                j = 0;
                while (j != 1) {
                    printf("1. Enqueue_using_rear\n");
                    printf("2. Dequeue_using_rear\n");
                    printf("3. Dequeue_using_front\n");
                    printf("4. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &c);

                    switch (c) {
                        case 1:
                            printf("Enter element to enqueue: ");
                            scanf("%d", &x);
                            enqueue_using_rear(x);
                            break;
                        case 2: {
                            int result = dequeue_using_rear();
                            if(result == -1)
                                printf("The queue is empty\n");
                            else
                                printf("The deleted element is: %d\n", result);
                            break;
                        }
                        case 3: {
                            int result = dequeue_using_front();
                            if(result == -1)
                                printf("The queue is empty\n");
                            else
                                printf("The deleted element is: %d\n", result);
                            break;
                        }
                        case 4:
                            printf("Exiting...\n");
                            j = 1;
                            break;
                        default:
                            printf("Invalid choice, please try again.\n");
                    }
                }
                break;
            case 2:
                j = 0;
                while (j != 1) {
                    printf("1. Enqueue_using_rear\n");
                    printf("2. Enqueue_using_front\n");
                    printf("3. Dequeue_using_front\n");
                    printf("4. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &c);

                    switch (c) {
                        case 1:
                            printf("Enter element to enqueue: ");
                            scanf("%d", &x);
                            enqueue_using_rear(x);
                            break;
                        case 2:
                            printf("Enter element to enqueue: ");
                            scanf("%d", &x);
                            enqueue_using_front(x);
                            break;
                        case 3: {
                            int result = dequeue_using_front();
                            if(result == -1)
                                printf("The queue is empty\n");
                            else
                                printf("The deleted element is: %d\n", result);
                            break;
                        }
                        case 4:
                            printf("Exiting...\n");
                            j = 1;
                            break;
                        default:
                            printf("Invalid choice, please try again.\n");
                    }
                }
                break;
            case 3:
                display();
                break;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return (rear + 1) % max == front;
}

void enqueue_using_rear(int value) {
    if (isFull()) {
        printf("The queue is full\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % max;
    queue[rear] = value;
}

void enqueue_using_front(int value) {
    if (isFull()) {
        printf("The queue is full\n");
        return;
    }
    if (isEmpty()) {
        rear = 0;
    }
    front = (front + max - 1) % max;
    queue[front] = value;
}

int dequeue_using_rear() {
    if (isEmpty()) {
        return -1;
    }
    int del = queue[rear];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        rear = (rear + max - 1) % max;
    }
    return del;
}

int dequeue_using_front() {
    if (isEmpty()) {
        return -1;
    }
    int deleted = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % max;
    }
    return deleted;
}

void display() {
    if (isEmpty()) {
        printf("The queue is empty\n");
        return;
    }
    printf("The queue is:\n");
    for (int i = front; i != rear; i = (i + 1) % max) {
        printf("%d\n", queue[i]);
    }
    printf("%d\n", queue[rear]);
}
