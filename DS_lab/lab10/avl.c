#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
    int height;
}node;

node* createnode(int data)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1; 
    return newnode;
}

int height(node* root)
{
    if (root == NULL) return 0;
    return root->height;
}

int balance_factor(node* root)
{
    if (root == NULL)return 0;
    return height(root->left) - height(root->right);
}

node* rotate_right(node* y)
{
    node* x = y->left;
    node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = MAX(height(y->left), height(y->right)) + 1;
    x->height = MAX(height(x->left), height(x->right)) + 1;
    return x;
}

node* rotate_left(node* x)
{
    node* y = x->right;
    node* T2 = y->left;
    y->left = x;
    x->right = T2;

    x->height = MAX(height(x->left), height(x->right)) + 1;
    y->height = MAX(height(y->left), height(y->right)) + 1;
    return y;
}

node* insert(node* node, int data)
{
    if (node == NULL) return createnode(data);

    if (data < node->data) node->left = insert(node->left, data);
    else if (data > node->data) node->right = insert(node->right, data);
    else return node;

    node->height = 1+ MAX(height(node->left),height(node->right));

    int balance = balance_factor(node);

    if (balance > 1 && data < node->left->data)
        return rotate_right(node);

    if (balance < -1 && data > node->right->data)
        return rotate_left(node);

    if (balance > 1 && data > node->left->data) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }
    if (balance < -1 && data < node->right->data) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node;
}

void printLevel(node* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void level_order_traversal(node* root) {
    int h = abs(height(root));
    for (int i = 1; i <= h; i++) {
        printLevel(root, i);
    }
}

int main()
{
    node* root = NULL; 
    int v;
    printf("Enter values to make a BST(-1 to exit)\n");
    while(1){
        printf("Enter val: ");
        scanf("%d",&v);
        if(v == -1)break;
        root = insert(root,v);
        printf("level order traversal: ");
        level_order_traversal(root);
        printf("\n");
    }
    return 0;
}