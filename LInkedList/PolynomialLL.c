#include <stdio.h>
#include <stdlib.h>

struct node {
    int pow;
    int coeff;
    struct node *next;
};

struct node *res_head = NULL;
struct node *res_tail = NULL;

struct node *createnode(int power, int coef) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    
    new_node->pow = power;
    new_node->coeff = coef;
    new_node->next = NULL;
    return new_node;
}

struct node *createpoly() {
    int n, p, c;
    struct node *head = NULL;
    struct node *tail = NULL;
    printf("Enter the number of nodes: \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the coefficient: \n");
        scanf("%d", &c);
        printf("Enter the power: \n");
        scanf("%d", &p);
        struct node *newnode = createnode(p, c);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }
    return head;
}

void add(struct node *first, struct node *second) {
    while (first != NULL && second != NULL) {
        if (first->pow > second->pow) {
            struct node *newnode = createnode(first->pow, first->coeff);
            if (res_head == NULL) {
                res_head = newnode;
                res_tail = newnode;
            } else {
                res_tail->next = newnode;
                res_tail = newnode;
            }
            first = first->next;
        } else if (second->pow > first->pow) {
            struct node *newnode = createnode(second->pow, second->coeff);
            if (res_head == NULL) {
                res_head = newnode;
                res_tail = newnode;
            } else {
                res_tail->next = newnode;
                res_tail = newnode;
            }
            second = second->next;
        } else {
            struct node *newnode = createnode(first->pow, first->coeff + second->coeff);
            if (res_head == NULL) {
                res_head = newnode;
                res_tail = newnode;
            } else {
                res_tail->next = newnode;
                res_tail = newnode;
            }
            first = first->next;
            second = second->next;
        }
    }
    while (first != NULL) {
        struct node *newnode = createnode(first->pow, first->coeff);
        if (res_head == NULL) {
            res_head = newnode;
            res_tail = newnode;
        } else {
            res_tail->next = newnode;
            res_tail = newnode;
        }
        first = first->next;
    }
    while (second != NULL) {
        struct node *newnode = createnode(second->pow, second->coeff);
        if (res_head == NULL) {
            res_head = newnode;
            res_tail = newnode;
        } else {
            res_tail->next = newnode;
            res_tail = newnode;
        }
        second = second->next;
    }
}

void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%dX^%d", temp->coeff, temp->pow);
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    printf("Create first polynomial:\n");
    struct node *first = createpoly();
    printf("Create second polynomial:\n");
    struct node *second = createpoly();
    printf("First polynomial: ");
    display(first);
    printf("Second polynomial: ");
    display(second);
    add(first, second);
    printf("Resultant polynomial: ");
    display(res_head);
    return 0;
}
