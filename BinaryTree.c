#include <stdio.h>
#include <stdlib.h>
struct tree {
    struct tree *left;
    struct tree *right;
    int val;
};
struct tree *createtree(struct tree *root);
void preorder(struct tree *root);
void preorder(struct tree *root);
void postorder(struct tree *root);
int main() {
    printf("Enter the value of the root: ");
    int val;
    scanf("%d", &val);
    struct tree *root = (struct tree *)malloc(sizeof(struct tree));
    root->val = val;
    root->left = NULL;
    root->right = NULL;
    createtree(root);
    inorder(root);
    return 0;
}
struct tree *createtree(struct tree *root) {
    int left,right;
    printf("Press 1 if you want to enter left of %d: ", root->val);
    scanf("%d", &left);
    if(left == 1){
        printf("Enter the value of left node: ");
        int leftval;
        scanf("%d", &leftval);
        struct tree *newleft = (struct tree *)malloc(sizeof(struct tree));
        newleft->val = leftval;
        newleft->left = NULL;
        newleft->right = NULL;
        root->left = newleft;
        createtree(newleft);
    }
    printf("Press 2 if you want to enter right of %d: ", root->val);
    scanf("%d", &right);
    if(right == 2){
        printf("Enter the value of right node: ");
        int rightval;
        scanf("%d", &rightval);
        struct tree *newright = (struct tree *)malloc(sizeof(struct tree));
        newright->val = rightval;
        newright->left = NULL;
        newright->right = NULL;
        root->right = newright;
        createtree(newright);
    }
    return root;
}
void preorder(struct tree *root) {
    if (root == NULL) return;
    printf("%d\n", root->val);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct tree *root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d\n", root->val);
    inorder(root->right);
}
void postorder(struct tree *root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\n", root->val);
}
