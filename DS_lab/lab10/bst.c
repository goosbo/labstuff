#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}node;

struct node* createNode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void inorder_traversal(node* root){
    if(root == NULL)return;
    inorder_traversal(root->left);
    printf("%d ",root->data);
    inorder_traversal(root->right);
}

void preorder_traversal(node* root){
    if(root == NULL)return;
    printf("%d ",root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(node* root){
    if(root == NULL)return;
    preorder_traversal(root->left);
    preorder_traversal(root->right);
    printf("%d ",root->data);
}

node* insert_node(node* root,node* val){
    if(root == NULL)return val;
    if(val->data <= root->data )root->left = insert_node(root->left,val);
    else root->right = insert_node(root->right,val);
    return root;
}

int search_node(node* root,int val){
    if(root == NULL) return 0;
    else if(root->data == val)return 1;
    else if(val < root->data) return search_node(root->left,val);
    else return search_node(root->right,val);
}

node* get_successor(node *curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

node* delete_node(node* root,int val){
    if(root == NULL) {
        printf("node not found\n");
        return root;
    }
    if(root->data > val)root->left = delete_node(root->left,val);
    else if(root->data < val) root->right = delete_node(root->right,val);
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        node* successor = get_successor(root);
        root->data = successor->data;
        root->right = delete_node(root->right,successor->data);

    }
    return root;
}

void getminmax(node* root,int* min, int* max){
    if(root == NULL){
        min = NULL;
        max == NULL;
        return;
    }
    node* minnode = root;
    while(minnode->left != NULL)minnode = minnode->left;
    *min = minnode->data;
    node* maxnode = root;
    while(maxnode->right != NULL)maxnode = maxnode->right;
    *max = maxnode->data;
}

int main(){
    node* root = NULL; 
    int v,c,min,max;
    printf("Enter values to make a BST(-1 to exit)\n");
    while(1){
        printf("Enter val: ");
        scanf("%d",&v);
        if(v == -1)break;
        node* newnode = createNode(v);
        root = insert_node(root,newnode);
    }
    printf("MENU\n1)Traversals\n2)Search\n3)Delete\n4)Minimum and Maximum element\n5)Exit\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&c);
        switch(c){
            case 1:
            printf("Inorder traversal: ");
            inorder_traversal(root);
            printf("\nPostorder traversal: ");
            postorder_traversal(root);
            printf("\nPreorder traversal: ");
            preorder_traversal(root);
            printf("\n");
            break;

            case 2:
            printf("enter search value: ");
            scanf("%d",&v);
            if(search_node(root,v))printf("element found\n");
            else printf("element not found\n");
            break;

            case 3:
            printf("enter value to be deleted: ");
            scanf("%d",&v);
            delete_node(root,v);
            printf("node deleted\n");
            break;

            case 4:
            getminmax(root,&min,&max);
            printf("Minimum element: %d\n",min);
            printf("Maximum element: %d\n",max);
            break;

            case 5:
            return 0;
            default:
            printf("invalid choice\n");
        }
    }
    
    
}