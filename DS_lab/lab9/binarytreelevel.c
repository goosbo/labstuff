#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* createTree() {
    int data;
    printf("\nEnter data (-1 for no node): ");
    scanf("%d", &data);
    
    if (data == -1) return NULL;
    struct Node* root = createNode(data);
    
    printf("\nEnter left child of %d:\n", data);
    root->left = createTree();
    
    printf("\nEnter right child of %d:\n", data);
    root->right = createTree();
    
    return root;
}

int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void printLevel(struct Node* root, int level) {
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

void levelOrderTraversal(struct Node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printLevel(root, i);
    }
}

int main() {
    struct Node* root = NULL;

    printf("Enter root node:\n");
    root = createTree();
    if (root == NULL) {
        printf("\nTree is empty!\n");
        return 0;
    }
    printf("\nLevel-order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");
    return 0;
}