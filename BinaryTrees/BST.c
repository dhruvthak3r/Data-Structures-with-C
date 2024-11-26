#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *left;
    struct node *right;
    int val;
};
struct node *createnode(int x){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node ->val = x;
    new_node ->left = NULL;
    new_node -> right = NULL;
    return new_node;
}
struct node *insert(struct node *root,int x){
    if(root == NULL){
        return createnode(x);
    }
    if(x > root->val){
        root -> right = insert(root-> right , x);
    }
    else{
        root -> left = insert(root -> left , x);
    }
    return root;
}
struct node *delete(struct node *root,int x){
    if(root == NULL){
        return NULL;
    }
    if(x < root->val){
        root -> left = delete(root -> left,x);
    }
    else if(x > root-> val){
        root -> right = delete(root -> right,x);
    }
    else{
        if(root -> left == NULL) return root -> right;
        else if(root -> right == NULL) return root -> left;
        else{
            struct node *min = root -> right;
            while(min -> left !=NULL){
                min = min -> left;
            }
            root -> val = min -> val;
            root -> right = delete(root -> right,min -> val);
        }
    }
    return root;
}
void preorder(struct node *root){
    if(root == NULL) return;
    printf("%d\n",root -> val);
    preorder(root -> left);
    preorder(root -> right);
}
void inorder(struct node *root){
    if(root == NULL) return;
    inorder(root -> left);
    printf("%d\n",root->val);
    inorder(root -> right);
}
void postorder(struct node *root){
    if(root == NULL) return;
    postorder(root -> left);
    postorder(root -> right);
    printf("%d\n",root -> val);
}
int height(struct node *root){
    if(root == NULL) return 0;
    int left = height(root -> left);
    int right = height(root -> right);
    return 1 + max(left,right);
}
int max(int a ,int b){
    if(a>=b) return a;
    return b;
}
int leafnodes(struct node *root){
    if(root == NULL) return 0;
    if(root ->left ==NULL&& root -> right == NULL) return 1;
    return leafnodes(root -> left) + leafnodes(root -> right);
}
struct node *mirror(struct node *root){
    if(root == NULL) return NULL;
    struct node *left = mirror(root -> left);
    struct node *right = mirror(root -> right);
    root -> right = left;
    root -> left = right;
    return root;
}
int main(){
    int choice,x;
    struct node *root = NULL;
    while(1){
        printf("1.insert\n");
        printf("2.delete\n");
        printf("3.height\n");
        printf("4.mirror\n");
        printf("5.count leafnodes\n");
        printf("6.inorder\n");
        printf("7.preorder\n");
        printf("8.postorder\n");
        printf("9.quit\n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        if(choice == 9) break;
        switch(choice){
            case 1:
            printf("enter the value to insert\n");
            scanf("%d",&x);
           root = insert(root,x);
            break;
            case 2:
            printf("enter the value to be deleted\n");
            scanf("%d",&x);
            root = delete(root,x);
            break;
            case 3:
            printf("the height of the tree is : %d\n",height(root));
            break;
            case 4:
            printf("the mirrored tree is : \n");
            inorder(mirror(root));
            break;
            case 5:
            printf("the number of leaf nodes is %d\n",leafnodes(root));
            break;
            case 6:
            inorder(root);
            break;
            case 7:
            preorder(root);
            break;
            case 8:
            postorder(root);
            break;
        }
    }
}

