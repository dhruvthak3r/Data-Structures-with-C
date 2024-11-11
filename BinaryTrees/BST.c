#include <stdio.h>
#include <stdlib.h>

struct treenode {
    int val;
    struct treenode *left;
    struct treenode *right;
};

struct treenode* createnode(int value);
struct treenode* insert(struct treenode *root, int value);
struct treenode* deleteNode(struct treenode *root, int value);
void preorder(struct treenode *root);
void inorder(struct treenode *root);
void postorder(struct treenode *root);
int countnodes(struct treenode *root);
void leafnodes(struct treenode *root);
int height(struct treenode *root);
int max(int a, int b);
struct treenode* mirror(struct treenode *node);
int leafnode = 0;
int main() {
    struct treenode *root = NULL;
    int choice, data, rootval;
    printf("Enter the value of root: ");
    scanf("%d", &rootval);
    root = createnode(rootval);
    while (1) {
        printf("\n1. Insert into BST\n");
        printf("2. Delete from BST\n");
        printf("3. Preorder traversal\n");
        printf("4. Inorder traversal\n");
        printf("5. Postorder traversal\n");
        printf("6. Count number of nodes \n");
        printf("7. Count number of external nodes\n");
        printf("8. Count number of internal nodes\n");
        printf("9. Count height \n");
        printf("10. Mirror the tree \n");
        printf("11. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 11) break;

        switch (choice) {
            case 1:
                printf("Enter the value of the node you want: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter the value of the node to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                break;
            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                break;
            case 6:
                printf("The number of nodes is %d\n", countnodes(root));
                break;
            case 7:
                leafnode = 0;
                leafnodes(root);
                printf("The number of external nodes is %d\n", leafnode);
                break;
            case 8:
                printf("The number of internal nodes is %d\n", countnodes(root) - leafnode);
                break;
            case 9:
                printf("The height of the tree is: %d\n", height(root));
                break;
            case 10:
                printf("The mirrored tree is:\n");
                struct treenode* copy = mirror(root);
                inorder(copy);
                break;
        }
    }
    return 0;
}
struct treenode* createnode(int value) {
    struct treenode *newnode = (struct treenode *)malloc(sizeof(struct treenode));
    newnode->val = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
struct treenode* insert(struct treenode *root, int value) {
    if (root == NULL) {
        return createnode(value);
    }
    if (value < root->val) {
        root->left = insert(root->left, value);
    } else if (value > root->val) {
        root->right = insert(root->right, value);
    } else {
        printf("The node is already present\n");
    }
    return root;
}
struct treenode* deleteNode(struct treenode *root, int value) {
    if (root == NULL) return root;

    if (value < root->val) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->val) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct treenode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct treenode *temp = root->left;
            free(root);
            return temp;
        }
        struct treenode *temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

void preorder(struct treenode *root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct treenode *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}
void postorder(struct treenode *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}
int countnodes(struct treenode *root) {
    if (root == NULL) return 0;
    return 1 + countnodes(root->left) + countnodes(root->right);
}
void leafnodes(struct treenode *root) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) leafnode++;
    leafnodes(root->left);
    leafnodes(root->right);
}
int height(struct treenode *root) {
    if (root == NULL) return 0;
    int left = height(root->left);
    int right = height(root->right);
    return 1 + max(left, right);
}
int max(int a, int b) {
    if(a >= b) return a;
    return b;
}
struct treenode* mirror(struct treenode *node) {
    if (node == NULL) return NULL;
    struct treenode *left = mirror(node->left);
    struct treenode *right = mirror(node->right);
    node->left = right;
    node->right = left;
    return node;
}
