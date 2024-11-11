#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;
void insert(int value);
void display();
void delete(int value);
void createlist();
void insertafter(int key, int value);
void insertbefore(int key, int value);
int main(){
    int data, choice, key;
    createlist();
    while(1){
        printf("1.display\n");
        printf("2.insert\n");
        printf("3.delete\n");
        printf("4.insert after\n");
        printf("5.insert before\n");
        printf("6.Quit\n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        if(choice == 6) break;
        switch(choice){
            case 1:
            display();
            break;
            case 2:
            printf("enter the value of the new node\n");
            scanf("%d",&data);
            insert(data);
            break;
            case 3:
            printf("enter the value of the node to be deleted\n");
            scanf("%d",&data);
            delete(data);
            break;
            case 4:
            printf("enter the key and value for the new node\n");
            scanf("%d %d",&key, &data);
            insertafter(key, data);
            break;
            case 5:
            printf("enter the key and value for the new node\n");
            scanf("%d %d",&key, &data);
            insertbefore(key, data);
            break;
            default:
            printf("Wrong choice\n");
            break;
        }
    }
}
void insert(int value){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> val = value;
    if(head == NULL && tail == NULL){
        head = temp;
        tail = temp;
        tail -> next = head;
        return;
    }
    tail -> next = temp;
    temp -> next = head;
    tail = temp;
}
void display(){
    if(head == NULL && tail == NULL){
        printf("The list is empty \n");
        return;
    }
    struct node *temp = head;
    do{
        printf("%d", temp->val);
        printf("->");
        temp = temp -> next;
    }while(temp!= head);
    printf("%d\n", head->val);
}
void delete(int value){
    if(head == NULL && tail == NULL){
        printf("The list is empty\n");
        return;
    }
    struct node *temp = head;
    if(head -> val == value){
        if(head == tail){
            free(head);
            head = NULL;
            tail = NULL;
            return;
        }
        head = head -> next;
        tail -> next = head;
        free(temp);
        return;
    }
    do{
        if(temp -> next -> val == value){
            struct node *nextnode = temp -> next -> next;
            if(temp->next == tail){
                tail = temp;
            }
            free(temp -> next);
            temp -> next = nextnode;
            return;
        }
        temp = temp -> next;
    }while(temp!=head);
    printf("Node with value %d not found\n", value);
}
void insertafter(int key, int value){
    if(head == NULL){
        printf("The list is empty\n");
        return;
    }
    struct node *temp = head;
    do{
        if(temp -> val == key){
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode -> val = value;
            newNode -> next = temp -> next;
            temp -> next = newNode;
            if(temp == tail){
                tail = newNode;
            }
            return;
        }
        temp = temp -> next;
    }while(temp != head);
    printf("Node with value %d not found\n", key);
}
void insertbefore(int key, int value){
    if(head == NULL){
        printf("The list is empty\n");
        return;
    }
    struct node *temp = head;
    struct node *prev = tail;
    do{
        if(temp -> val == key){
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode -> val = value;
            newNode -> next = temp;
            prev -> next = newNode;
            if(temp == head){
                head = newNode;
            }
            return;
        }
        prev = temp;
        temp = temp -> next;
    }while(temp != head);
    printf("Node with value %d not found\n", key);
}
void createlist(){
    printf("enter the number of nodes :");
    int numnodes,value;
    scanf("%d",&numnodes);
    for(int i=0;i<numnodes;i++){
        printf("enter the value of the node to be added\n");
        scanf("%d",&value);
        insert(value);
    }
}
