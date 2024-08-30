#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node *prev;
    struct Node *next;
    int val;
};
struct Node *CreateList(struct Node *head);
struct Node *InsertAtEnd(struct Node *head,int value);
void display(struct Node *head);
struct Node *InsertAtBegining(struct Node *head,int value);
struct Node *InsertBefore(struct Node *head,int value,int newvalue);
struct Node *InsertAfter(struct Node *head,int value,int newvalue);
struct Node *DeleteNode(struct Node *head,int value);
void DisplayReverse( struct Node *head);
struct Node *InsertAtPostition(struct Node *head,int position,int value);
struct Node *Reverse(struct Node *head);
void Length(struct Node *head);
int main(){
    struct Node *head=NULL;
    head=CreateList(head);
    int choice,value,newvalue,position;
    while(1){
        printf("\n");
        printf("1.Display list\n");
        printf("2.Insert at the begining of the list\n");
        printf("3.Insert at the end of the list\n");
        printf("4.Delete a specified node\n");
        printf("5.Insert before a specifed node\n");
        printf("6.Insert after a specified node\n");
        printf("7.Insert a node at a specified postion\n");
        printf("8.Reverse the list\n");
        printf("9.Display the list in reverse\n");
        printf("10.count number of nodes in the list\n");
        printf("11. Quit\n");
        scanf("%d",&choice);
        if(choice==11) break;
        switch(choice){
            case 1:
            display(head);
            break;
            case 2:
            printf("enter the value of the node to be inserted at the begining\n");
            scanf("%d",&value);
            head=InsertAtBegining(head,value);
            break;
            case 3:
            printf("enter the value of the node to be inserted at the end\n");
            scanf("%d",&value);
            head=InsertAtEnd(head,value);
            break;
            case 4:
            printf("enter the value of the of the node to be deleted : \n");
            scanf("%d",&value);
            head=DeleteNode(head,value);
            break;
            case 5:
            printf("enter the value of new node");
            scanf("%d",&newvalue);
            printf("Enter the element before which to insert : \n");
            scanf("%d",&value);
            head=InsertBefore(head,value,newvalue);
            break;
            case 6:
             printf("enter the value of new node");
            scanf("%d",&newvalue);
            printf("Enter the element after which to insert : \n");
            scanf("%d",&value);
            head=InsertAfter(head,value,newvalue);
            break;
            case 7:
            printf("enter the position");
            scanf("%d",&position);
            printf("enter the value of new node");
            scanf("%d",&newvalue);
            head=InsertAtPostition(head,position,value);
            break;
            case 8:
            head=Reverse(head);
            break;
            case 9:
            DisplayReverse(head);
            break;
            case 10:
            Length(head);
            break;
            default:
            printf("wrong choice");
        }
    }
    display(head);
}
struct Node *CreateList(struct Node *head){
    int num,value;
    printf("enter the number of nodes to be added");
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        printf("enter the value of the node : \n");
        scanf("%d",&value);
        head=InsertAtEnd(head,value);
    }
    return head;
}
struct Node *InsertBefore(struct Node *head,int value,int newvalue){
    if(head==NULL){
        printf("the list is empty");
        return head;
    }
    struct Node *temp=head;
    while(temp!=NULL){
        if(temp->val==value) break;
        temp=temp->next;
    }
    if(temp==NULL) printf("the node is not present in the linked list \n");
    else{
        struct Node *before=temp->prev;
        struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
        newnode->val=newvalue;
        temp->prev=newnode;
        newnode->next=temp;
        newnode->prev=before;
        before->next=newnode;
    }
    return head;
}
struct Node *InsertAfter(struct Node *head,int value,int newvalue){
    if(head==NULL){
        printf("the list is empty");
        return head;
    }
    struct Node *temp=head;
    while(temp!=NULL){
        if(temp->val==value) break;
        temp=temp->next;
    }
    if(temp==NULL) printf("the node is not present in the linked list \n");
    else{
        struct Node *after=temp->next;
        struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
        newnode->val=newvalue;
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=after;
        after->prev=newnode;
    }
    return head;
}
struct Node *InsertAtEnd(struct Node *head,int value){
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->val=value;
    temp->next=NULL;
    if(head==NULL) return temp;
    struct Node *tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    return head;
}
struct Node *InsertAtBegining(struct Node *head,int value){
    if(head==NULL){
        printf("the list is empty");
        return head;
    }
    struct Node *temp=(struct Node*)malloc(sizeof (struct Node));
    temp->val=value;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}
struct Node *InsertAtPostition(struct Node *head,int position,int value){
    if(head==NULL){
        printf("the linkedlist is empty");
        return head;
    }
    if(position==0){
        head=InsertAtBegining(head,value);
        return head;
    }
    struct Node *temp=head;
    for(int i=0;i<position;i++){
        temp=temp->next;
    }
    struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->val=value;
    struct Node *before=temp->prev;
    before->next=newnode;
    newnode->prev=before;
    newnode->next=temp;
    temp->prev=newnode;
    return head;
}
struct Node *DeleteNode(struct Node *head,int value){
    if(head==NULL){
        printf("Empty linked list");
        return head;
    }
    if(head->val==value){
        head=head->next;
        return head;
    }
    struct Node *temp=head;
    while(temp!=NULL){
        if(temp->val==value) break;
        temp=temp->next;
    }
    if(temp==NULL) printf("the node is not present in the linked list\n");
    else{
        temp->prev->next=temp->next;
    }
    return head;
}
void Length(struct Node *head){
    if(head==NULL){
        printf("the list is empty");
        return;
    }
    int length=0;
    struct Node *temp=head;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    printf("The length of the linked list is %d\n", length);
}
void display(struct Node *head){
    if(head==NULL){
        printf("the list is empty");
        return;
    }
    struct Node*temp=head;
    while(temp!=NULL){
       printf("%d",temp->val);
       printf("->");
       temp=temp->next;
    }
}
void DisplayReverse( struct Node *head){
    if(head==NULL){
        printf("the linked list is empty");
        return;
    }
    struct Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    printf("the linkedlist printed in reverse is\n");
    while(temp!=head){
        printf("%d\n",temp->val);
        printf("->");
        temp=temp->prev;
    }
}
struct Node* Reverse(struct Node* head) {
    if (head == NULL) {
        printf("The linked list is empty\n");
        return head;
    }
    struct Node *before,*curr;
	before=head;
	curr=before->next;
	before->next=NULL;
	before->prev=curr;
	while(curr!=NULL)
	{
		curr->prev=curr->next;
		curr->next=before;
		before=curr;
		curr=curr->prev; 
	}
	head=before;
    return head;
}

