#include<stdio.h>
#include<stdlib.h>
struct node{
    int power;
    int coeff;
    struct node *next;
};
void add(struct node *first,struct node *second);
struct node *createpoly();
struct node *createnode(int constant, int pow);
void display();
struct node *head = NULL;
int main(){
    struct node *first = createpoly();
    struct node *second = createpoly();
    add(first,second);
    display();
}

void add(struct node *first,struct node *second){
    struct node *result = NULL;
    struct node *result_tail = NULL;
    while(first !=NULL && second!=NULL){
        if(first -> power > second -> power){
            struct node *newNode = createnode(first -> coeff , first -> power);
            if(result == NULL) {
                result = result_tail = newNode;
            } else {
                result_tail -> next = newNode;
                result_tail = newNode;
            }
            first = first -> next;
        }
        else if(second -> power > first -> power){
            struct node *newNode = createnode(second -> coeff , second -> power);
            if(result == NULL) {
                result = result_tail = newNode;
            } else {
                result_tail -> next = newNode;
                result_tail = newNode;
            }
            second = second -> next;
        }
        else{
            struct node *newNode = createnode((first -> coeff + second -> coeff) , first -> power);
            if(result == NULL) {
                result = result_tail = newNode;
            } else {
                result_tail -> next = newNode;
                result_tail = newNode;
            }
            first = first -> next;
            second = second -> next;
        }
    }
    while(first !=NULL){
        struct node *newNode = createnode(first -> coeff , first -> power);
        if(result == NULL) {
            result = result_tail = newNode;
        } else {
            result_tail -> next = newNode;
            result_tail = newNode;
        }
        first = first -> next;
    }
    while(second !=NULL){
        struct node *newNode = createnode(second -> coeff , second -> power);
        if(result == NULL) {
            result = result_tail = newNode;
        } else {
            result_tail -> next = newNode;
            result_tail = newNode;
        }
        second = second -> next;
    }
    head = result;
}

struct node *createpoly(){
    struct node *poly = NULL;
    struct node *poly_tail = NULL; 
    printf("enter the number of nodes\n");
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        printf("enter the co-efficient\n");
        int newcoeff;
        scanf("%d", &newcoeff);
        printf("enter the power\n");
        int newpow;
        scanf("%d", &newpow);
        struct node *newNode = createnode(newcoeff, newpow);
        if(poly == NULL) {
            poly = poly_tail = newNode;
        } else {
            poly_tail -> next = newNode;
            poly_tail = newNode;
        }
    }
    return poly;
}

struct node *createnode(int constant, int pow){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> coeff = constant;
    temp -> power = pow;
    temp -> next = NULL;
    return temp;
}

void display(){
    struct node *ptr = head;
    while(ptr != NULL){
        printf("%dX^%d ", ptr->coeff, ptr->power);
        ptr = ptr -> next;
        if(ptr != NULL)
            printf("+ ");
    }
    printf("\n");
}
