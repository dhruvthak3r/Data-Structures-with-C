#include <stdio.h>
#include <stdlib.h>
struct Node {
    int val;
    struct Node *next;
};
struct Node* InsertBeginning(struct Node *head, int value);
struct Node* InsertAtEnd(struct Node *head, int value);
struct Node* CreateList(struct Node *head);
struct Node* InsertAtPosition(struct Node *head,int value,int position);
struct Node* InsertAfter(struct Node *head,int value,int newvalue);
struct Node* InsertBefore(struct Node *head,int value,int newvalue);
struct Node* DeleteNode(struct Node *head,int value);
struct Node* SearchNode(struct Node *head,int value);
void CountNodes(struct Node *head);
void display(struct Node *head);
int main()
{
    struct Node *head=NULL;
    head=CreateList(head);
    int choice,value,newvalue,position;
    while(1){
        printf("\n");
        printf("1: To Display the List\n");
        printf("2.Count the number of nodes\n");
		printf("3.Search for an element\n");
		printf("4.Insert in empty list / Insert in beginning of the list\n");
		printf("5.Insert a node at the end of the list\n");
		printf("6.Insert a node after a specified node\n");
		printf("7.Insert a node before a specified node\n");
		printf("8.Insert a node at a given position\n");
		printf("9.Delete a node\n");
                printf("10.Quit\n\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
        
        if(choice==10)
			break;

		switch(choice)
		{
		 case 1:
			display(head);
			break;
		 case 2:
			CountNodes(head);
			break;
		 case 3:
			printf("Enter the element to be searched : ");
			scanf("%d",&value);
			head=SearchNode(head,value);
			break;
		 case 4:
			printf("Enter the element to be inserted : ");
			scanf("%d",&value);
			head=InsertBeginning(head,value);
			break;
		 case 5:
			printf("Enter the element to be inserted : ");
			scanf("%d",&value);
			head=InsertAtEnd(head,value);
			break;
		 case 6:
			printf("Enter the element to be inserted : ");
			scanf("%d",&value);
			printf("Enter the element after which to insert : ");
			scanf("%d",&newvalue);
			head=InsertAfter(head,value,newvalue);
			break;
		 case 7:
			printf("Enter the element to be inserted : ");
			scanf("%d",&value);
			printf("Enter the element before which to insert : ");
			scanf("%d",&newvalue);
			head=InsertBefore(head,value,newvalue);
			break;
		 case 8:
			printf("Enter the element to be inserted : ");
			scanf("%d",&value);
			printf("Enter the position at which to insert : ");
			scanf("%d",&position);
			head=InsertAtPosition(head,value,position);
			break;
		 case 9:
			printf("Enter the element to be deleted : ");
			scanf("%d",&value);
			head=DeleteNode(head,value);	
			break;
		 default:
			 printf("Wrong choice\n");
		}
	}
    display(head);
    return 0;
}
struct Node* CreateList(struct Node *head){
    int numnodes,val;
    printf("enter the number of nodes to be added");
    scanf("%d",&numnodes);
    for(int i=0;i<numnodes;i++){
        printf("Enter the next element to be inserted : ");
        scanf("%d",&val);
        head=InsertAtEnd(head,val);
    }
    return head;
}
struct Node* SearchNode(struct Node *head,int value){
    struct Node *temp=head;
    int position=0;
    while(temp!=NULL){
        if(temp->val==value) break;
        position++;
        temp=temp->next;
    }
    if(temp==NULL) printf("The Node is not in the present in the linked ist");
    else{
        printf("The Node is present in the position",position);
    }
    return head;
}
void CountNodes(struct Node *head){
    struct Node *temp=head;
    int length=0;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    printf("the number of nodes is " , length);
}
struct Node* InsertBeginning(struct Node *head, int value) {
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->val = value;
    temp->next = head;
    head = temp;
    return head;
}
struct Node* InsertAtEnd(struct Node *head, int value) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->val = value;
    temp->next = NULL;
    if (head == NULL) {
        return temp;
    }
    struct Node *tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = temp;
    return head;
}
struct Node* InsertAtPosition(struct Node *head,int value,int position){
    struct Node *temp=head;
    if(position==0){
        head=InsertBeginning(head,value);
    }
    for(int i=0;i<position-1;i++){
        temp=temp->next;
    }
    struct Node*next=temp->next;
    struct Node *NewNode=(struct Node *)malloc(sizeof(struct Node));
    NewNode->val=value;
    temp->next=NewNode;
    NewNode->next=next;
    return head;
}
struct Node* InsertAfter(struct Node *head,int value,int newvalue){
    struct Node *temp=head;
    while(temp!=NULL)
    {
        if(temp->val==value)break;
        temp=temp->next;
    }
    if(temp==NULL) printf("Not present in the LinkedList");
    else{
        struct Node *nextnode=temp->next;
        struct Node *NewNode=(struct Node *)malloc(sizeof(struct Node));
        NewNode->val=newvalue;
        temp->next=NewNode;
        NewNode->next=nextnode;
    }
    return head;
}
struct Node* InsertBefore(struct Node *head,int value,int newvalue){
    if(head->val==value){
        head=InsertBeginning(head,newvalue);
    }
    struct Node *temp=head;
    while(temp->next!=NULL)
    {
        if(temp->next->val==value) break;
        temp=temp->next;
    }
    if(temp->next==NULL) printf("Not present in the LinkedList");
    else{
       struct Node *nextnode=temp->next;
       struct Node *NewNode=(struct Node *)malloc(sizeof(struct Node));
       NewNode->val=newvalue;
       temp->next=NewNode;
       NewNode->next=nextnode;
    }
    return head;
}
struct Node* DeleteNode(struct Node *head,int value){
    struct Node *temp=head;
    while(temp->next!=NULL)
    {
        if(temp->next->val==value) break;
        temp=temp->next;
    }
    if(temp->next==NULL) printf("Not present in the LinkedList");
    else{
        temp->next=temp->next->next;
    }
    return head;
}
void display(struct Node *head)
{
    if(head==NULL){
        printf("The List is Empty");
        return;
    }
    struct Node *temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->val);
        printf("->");
        temp=temp->next;
    }
}


