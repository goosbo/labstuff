#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next,*prev;
} node;

node* create_node(int data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insert_last(node** head,node** tail, int data){
    node* new_node = create_node(data);
    if(*head == NULL) {
        *head = new_node;
        *tail = new_node;
        return;
    }

    (*tail)->next = new_node;
    new_node->prev = *tail;
    *tail = new_node;
}

void delete_last(node** head,node** tail){
    if(*head == NULL) {
        return;
    }
    if(*tail == *head){
        *head = NULL;
        *tail = NULL;
        return;
    }
    (*tail)->prev->next = NULL;
    *tail = (*tail)->prev;
}

void insert(node** head, node** tail, int data, int pos){
    node* new_node = create_node(data),*temp = *head;
    
    if(*head == NULL && pos > 1) return;
    else if(*head == NULL){
        *head = new_node;
        *tail = new_node;
        return;
    }

    for(int i = 1; i < pos; i++) {
        if(temp == NULL) return;
        temp = temp->next;
    }
    if(temp == NULL){
        insert_last(head,tail,data);
        return;
    }
    if(temp == *head){
        (*head)->prev = new_node;
        new_node->next = *head;
        *head = new_node;
        return;
    }
    temp->prev->next = new_node;
    new_node->prev = temp->prev;
    new_node->next = temp;
    temp->prev = new_node;

}

void delete(node** head,node** tail, int pos){
    node* temp = *head;
    if(*head == NULL) return;
    for(int i = 1; i < pos; i++){
        temp = temp->next;
        if(temp == NULL) return;
    }
    if(temp == *head){
        if(tail == head)*tail = (*tail)->next;
        *head = (*head)->next;
        return;
    }
    if(temp == *tail){
        delete_last(head,tail);
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void insert_after(node** head, node** tail, int data,int val){
    node* new_node = create_node(data), *temp = *head;
    int pos = 1;
    if(*head == NULL) return;
    while(temp != NULL && temp->data != val){
        temp = temp->next;
        pos++;
    }
    if(temp == NULL) return;
    insert(head,tail,data,pos+1);
}

void insert_before(node** head, node** tail, int data,int val){
    node* new_node = create_node(data), *temp = *head;
    int pos = 1;
    if(*head == NULL) return;
    while(temp != NULL && temp->data != val){
        temp = temp->next;
        pos++;
    }
    if(temp == NULL) return;
    insert(head,tail,data,pos);
}

void traverse(node* head){
    node* temp = head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void traverse_reverse(node* tail){
    node* temp = tail;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main(){
    int c,e,pos,b;
    node* head = NULL, *tail = NULL;

    printf("Enter one of the following options\n");
    printf("1 Insert an element at the rear end of the list\n");
    printf("2 Delete an element from the rear end of the list\n");
    printf("3 Insert an element at a given position in the list\n");
    printf("4 Delete an element from a given position in the list\n");
    printf("5 Insert an element after a node containing a specific value\n");
    printf("6 Insert an element before a node containing a specific value\n");
    printf("7 Traverse the list in forward direction\n");
    printf("8 Traverse the list in reverse direction\n");
    printf("9 exit\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&c);
        switch(c){
            case 1:
            printf("Enter element: ");
            scanf("%d",&e);
            insert_last(&head,&tail,e);
            break;

            case 2:
            delete_last(&head,&tail);
            break;

            case 3:
            printf("Enter element: ");
            scanf("%d",&e);
            printf("Enter position: ");
            scanf("%d",&pos);
            insert(&head,&tail,e,pos);
            break;

            case 4:
            printf("Enter position: ");
            scanf("%d",&pos);
            delete(&head,&tail,pos);
            break;

            case 5:
            printf("Enter element: ");
            scanf("%d",&e);
            printf("Enter value: ");
            scanf("%d",&b);
            insert_after(&head,&tail,e,b);
            break;

            case 6:
            printf("Enter element: ");
            scanf("%d",&e);
            printf("Enter value: ");
            scanf("%d",&b);
            insert_before(&head,&tail,e,b);
            break;

            case 7:
            traverse(head);
            break;

            case 8:
            traverse_reverse(tail);
            break;
            
            case 9:
            return 0;

            default:
            printf("invalid input\n");
        }
    }
    
}