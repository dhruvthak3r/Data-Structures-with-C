#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct node *head = NULL;

struct node *createnode(int value);
void create_list();
void insert_at_end(int x);
void insert_at_beg(int x);
void delete_value(int x);
void insert_before(int x, int new_value);
void insert_after(int x, int new_value);
void insert_at_position(int pos, int value);
void delete_at_position(int pos);
void display();

int main() {
    int choice, data, pos;
    while (1) {
        printf("1. Display\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Insert before\n");
        printf("5. Insert after\n");
        printf("6. Insert at position\n");
        printf("7. Delete value\n");
        printf("8. Delete at position\n");
        printf("9. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 9) break;
        switch (choice) {
            case 1:
                display();
                break;
            case 2:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &data);
                insert_at_beg(data);
                break;
            case 3:
                printf("Enter value to insert at end: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case 4:
                printf("Enter value to insert before: ");
                scanf("%d", &data);
                int before_value;
                printf("Enter the value before which to insert: ");
                scanf("%d", &before_value);
                insert_before(before_value, data);
                break;
            case 5:
                printf("Enter value to insert after: ");
                scanf("%d", &data);
                int after_value;
                printf("Enter the value after which to insert: ");
                scanf("%d", &after_value);
                insert_after(after_value, data);
                break;
            case 6:
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insert_at_position(pos, data);
                break;
            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                delete_value(data);
                break;
            case 8:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete_at_position(pos);
                break;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}

struct node *createnode(int value) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->val = value;
    temp->next = NULL;
    return temp;
}

void create_list() {
    int n, x;
    printf("Enter initial number of nodes: \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the value of the new node: \n");
        scanf("%d", &x);
        insert_at_end(x);
    }
}

void insert_at_end(int x) {
    struct node *newnode = createnode(x);
    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void insert_at_beg(int x) {
    struct node *newnode = createnode(x);
    if (head == NULL) {
        head = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }
}

void delete_value(int x) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    struct node *temp = head;
    struct node *prev = NULL;
    if (head->val == x) {
        head = head->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->val != x) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value not found in the list\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void insert_before(int x, int new_value) {
    struct node *newnode = createnode(new_value);
    struct node *temp = head;
    struct node *prev = NULL;
    while (temp != NULL && temp->val != x) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("The node is not present in the linked list\n");
        return;
    }
    if (prev == NULL) {
        newnode->next = head;
        head = newnode;
    } else {
        prev->next = newnode;
        newnode->next = temp;
    }
}

void insert_after(int x, int new_value) {
    struct node *newnode = createnode(new_value);
    struct node *temp = head;
    while (temp != NULL && temp->val != x) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("The node is not present in the linked list\n");
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void insert_at_position(int pos, int value) {
    struct node *newnode = createnode(value);
    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }
    struct node *temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("The position is out of range\n");
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_at_position(int pos) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    struct node *temp = head;
    if (pos == 1) {
        head = temp->next;
        free(temp);
        return;
    }
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("The position is out of range\n");
        return;
    }
    struct node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void display() {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    struct node *temp = head;
    printf("The linked list is:\n");
    while (temp != NULL) {
        printf("%d\n", temp->val);
        temp = temp->next;
    }
}
