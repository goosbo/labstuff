#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Stack {
    struct Node** arr;
    int top;
    int size;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Stack* createStack(int size) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (struct Node**)malloc(stack->size * sizeof(struct Node*));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->size - 1;
}

void push(struct Stack* stack, struct Node* node) {
    if (isFull(stack)) {
        stack->size *= 2;
        stack->arr = (struct Node**)realloc(stack->arr, stack->size * sizeof(struct Node*));
    }
    stack->arr[++stack->top] = node;
}

struct Node* pop(struct Stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->arr[stack->top--];
}

struct Node* peek(struct Stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->arr[stack->top];
}

void freeStack(struct Stack* stack) {
    free(stack->arr);
    free(stack);
}

void inorderIterative(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    
    struct Stack* stack = createStack(100);
    struct Node* current = root;
    
    printf("Inorder Traversal: ");
    
    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }
        
        current = pop(stack);
        printf("%d ", current->data);
        current = current->right;
    }
    
    printf("\n");
    freeStack(stack);
}

void postorderIterative(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    
    struct Stack* stack1 = createStack(100);
    struct Stack* stack2 = createStack(100);
    
    push(stack1, root);
    
    while (!isEmpty(stack1)) {
        struct Node* node = pop(stack1);
        push(stack2, node);
        
        if (node->left)
            push(stack1, node->left);
        if (node->right)
            push(stack1, node->right);
    }
    
    printf("Postorder Traversal: ");
    while (!isEmpty(stack2)) {
        struct Node* node = pop(stack2);
        printf("%d ", node->data);
    }
    printf("\n");
    
    freeStack(stack1);
    freeStack(stack2);
}

void preorderIterative(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    
    struct Stack* stack = createStack(100);
    push(stack, root);
    
    printf("Preorder Traversal: ");
    
    while (!isEmpty(stack)) {
        struct Node* node = pop(stack);
        printf("%d ", node->data);
        
        if (node->right)
            push(stack, node->right);
        if (node->left)
            push(stack, node->left);
    }
    
    printf("\n");
    freeStack(stack);
}

struct Node* findParent(struct Node* root, int value) {
    if (root == NULL)
        return NULL;
    
    if ((root->left && root->left->data == value) || 
        (root->right && root->right->data == value))
        return root;
    
    struct Node* leftResult = findParent(root->left, value);
    if (leftResult != NULL)
        return leftResult;
    
    return findParent(root->right, value);
}

int findHeight(struct Node* node) {
    if (node == NULL)
        return -1;
    
    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int printAncestors(struct Node* root, int value) {
    if (root == NULL)
        return 0;
    
    if (root->data == value)
        return 1;
    
    if (printAncestors(root->left, value) || 
        printAncestors(root->right, value)) {
        printf("%d ", root->data);
        return 1;
    }
    
    return 0;
}

int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    
    if (root->left == NULL && root->right == NULL)
        return 1;
    
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

void freeTree(struct Node* root) {
    if (root == NULL)
        return;
    
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

struct Node* findNode(struct Node* root, int value) {
    if (root == NULL)
        return NULL;
    
    if (root->data == value)
        return root;
    
    struct Node* leftResult = findNode(root->left, value);
    if (leftResult != NULL)
        return leftResult;
    
    return findNode(root->right, value);
}

void insertNode(struct Node** root) {
    int value, parentValue, choice;
    
    printf("Enter the value for the new node: ");
    scanf("%d", &value);
    
    if (*root == NULL) {
        *root = createNode(value);
        printf("Node %d inserted as root.\n", value);
        return;
    }
    
    printf("Enter the parent node value: ");
    scanf("%d", &parentValue);
    
    struct Node* parent = findNode(*root, parentValue);
    
    if (parent == NULL) {
        printf("Parent node %d not found in the tree.\n", parentValue);
        return;
    }
    
    printf("Insert as:\n1. Left child\n2. Right child\nChoice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        if (parent->left != NULL) {
            printf("Left child already exists for node %d.\n", parentValue);
        } else {
            parent->left = createNode(value);
            printf("Node %d inserted as left child of %d.\n", value, parentValue);
        }
    } else if (choice == 2) {
        if (parent->right != NULL) {
            printf("Right child already exists for node %d.\n", parentValue);
        } else {
            parent->right = createNode(value);
            printf("Node %d inserted as right child of %d.\n", value, parentValue);
        }
    } else {
        printf("Invalid choice.\n");
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;
    
    char continue_building = 'y';
    while (continue_building == 'y' || continue_building == 'Y') {
        insertNode(&root);
        printf("\nDo you want to add more nodes? (y/n): ");
        scanf(" %c", &continue_building);
        printf("\n");
    }
    
    if (root == NULL) {
        printf("No tree created. Exiting...\n");
        return 0;
    }
    
    do {
        printf("MENU\n");
        printf("1. Inorder Traversal\n");
        printf("2. Postorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Find Parent of a Node\n");
        printf("5. Print Height of Tree\n");
        printf("6. Print Ancestors of a Node\n");
        printf("7. Count Leaf Nodes\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch (choice) {
            case 1:
                inorderIterative(root);
                break;
                
            case 2:
                postorderIterative(root);
                break;
                
            case 3:
                preorderIterative(root);
                break;
                
            case 4:
                printf("Enter the node value to find its parent: ");
                scanf("%d", &value);
                if (root == NULL) {
                    printf("Tree is empty.\n");
                    continue;
                }
                
                if (root->data == value) {
                    printf("Node %d is the root node and has no parent.\n", value);
                    continue;
                }
                
                struct Node* parent = findParent(root, value);
                
                if (parent != NULL)
                    printf("Parent of %d is: %d\n", value, parent->data);
                else
                    printf("Node %d not found in the tree.\n", value);
                break;
                
            case 5:
                if (root == NULL) {
                    printf("Tree is empty. Height: -1\n");
                    continue;
                }
                
                int height = findHeight(root);
                printf("Height of the tree: %d\n", height);
                break;
                
            case 6:
                printf("Enter the node value to find its ancestors: ");
                scanf("%d", &value);
                if (root == NULL) {
                    printf("Tree is empty.\n");
                    continue;
                }
                
                if (root->data == value) {
                    printf("Node %d is the root and has no ancestors.\n", value);
                    continue;
                }
                
                printf("Ancestors of %d: ", value);
                if (!printAncestors(root, value))
                    printf("Node not found in the tree.");
                printf("\n");
                break;
                
            case 7:
                int count = countLeafNodes(root);
                printf("Number of leaf nodes: %d\n", count);
                break;
                
            case 0:
                printf("exiting");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
    } while (choice != 0);
    
    freeTree(root);
    return 0;
}