#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 10

int q[max];
int rear = -1;
int front = -1;

bool isFull();
bool isEmpty();
void Enqueue(int val);
int Dequeue();
int size();
void display();

int main() {
    printf("Enter your choice:\n");
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

bool isFull() {
    return rear == max - 1;
}

bool isEmpty() {
    return front == -1 || front == rear + 1;
}

void Enqueue(int val) {
    if (isFull()) {
        printf("The queue is full\n");
        return;
    }
    if (front == -1)
        front = 0;
    q[++rear] = val;
}

int Dequeue() {
    if (isEmpty()) {
        printf("The queue is empty\n");
        exit(1);
    }
    int delete = q[front];
    front++;
    return delete;
}

int size() {
    if (isEmpty())
        return 0;
    return rear - front + 1;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("The queue is: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}
