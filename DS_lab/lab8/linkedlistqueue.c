#include "stdio.h"
#include "stdlib.h"
typedef struct node{
    int val;
    struct node* next;
}node;

void enqueue(node** top,node** rear,int val){
    node* newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("queue is full\n");
        return;
    }
    newnode->val = val;
    if(*top == NULL){
        *top = newnode;
        *rear = newnode;
    }
    else{
        (*rear)->next = newnode;
        *rear = (*rear)->next;
    }
}

int dequeue(node** top,node** rear){
    if(*top == NULL){
        printf("queue is empty\n");
        return -1;
    }
    node* temp = *top;
    int val = (*top)->val;
    if(*top == *rear){
        *top = NULL;
        *rear = NULL;
    }
    else *top = (*top)->next;
    free(temp);
    return val;
}

void print(node* top, node* rear){
    node* temp = top;
    if(temp == NULL)return;
    while(temp!=rear){
        printf("%d ",temp->val);
        temp = temp->next;
    }
    printf("%d\n",rear->val);
}

int main(){
    int choice,n;
    node* top = NULL;
    node* rear = NULL;

    printf("MENU\n1.Enqueue\n2.Dequeue\n3.Display\n4.EXIT\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter number: ");
            scanf("%d",&n);
            enqueue(&top,&rear,n);
            break;
        case 2:
            n = dequeue(&top,&rear);
            printf("Dequeued %d\n",n);
            break;
        case 3:
            print(top,rear);
            break;
        case 4:
        return 0;
        default:
            printf("invalid input\n");
            return 1;
        }
    }
}