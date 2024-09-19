#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct node {
    int val;
    struct node *next;
};

void enqueue(int value);
int dequeue();
int peek();
void display();
int size();

struct node *front = NULL;
struct node *rear = NULL;

int main() {
    int choice, data;
    while (1) {
        printf("1.Display : \n");
        printf("2.Enqueue : \n");
        printf("3.Dequeue : \n");
        printf("4.Peek : \n");
        printf("5.Size : \n");
        printf("6.Quit : \n");
        printf("enter your choice : \n");
        scanf("%d", &choice);
        if (choice == 6) break;
        switch (choice) {
            case 1:
                display();
                break;
            case 2:
                printf("enter the element you want to enqueue : \n");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 3:
                printf("the deleted element is %d\n", dequeue());
                break;
            case 4:
                printf("the peek of the queue is %d\n", peek());
                break;
            case 5:
                printf("the size of the queue is %d\n", size());
                break;
            default:
                printf("wrong choice \n");
                break;
        }
    }
}

void enqueue(int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->val = value;
    newnode->next = NULL;
    if (front == NULL) {
        front = newnode;
        rear = newnode;
        return;
    }
    rear->next = newnode;
    rear = newnode;
}

int dequeue() {
    if (front == NULL) {
        printf("the queue is empty \n");
        exit(1);
    }
    if (front == rear) {
        int last = front->val;
        front = NULL;
        rear = NULL;
        return last;
    }
    int delete = front->val;
    front = front->next;
    return delete;
}

int peek() {
    if (front == NULL) {
        printf("the queue is empty \n");
        exit(1);
    }
    return front->val;
}

void display() {
    if (front == NULL) {
        printf("the queue is empty \n");
        return;
    }
    struct node *temp = front;
    printf("the queue is : \n");
    while (temp != rear) {
        printf("%d\n", temp->val);
        temp = temp->next;
    }
    printf("%d\n", temp->val);
}

int size() {
    if (front == NULL) return 0;
    int len = 0;
    struct node *temp = front;
    while (temp != rear) {
        len++;
        temp = temp->next;
    }
    return len + 1;
}
