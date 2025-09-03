#include "stdio.h"
#include "stdlib.h"

typedef struct node{
    int data;
    struct node* next;
}node;

node* create_node(int data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
}

void insert_end(node** first,node** last,int data){
    node* new_node = create_node(data);
    if(*first == NULL){
        new_node->next = new_node;
        *first = new_node;
        *last = new_node;
        return;
    }
    (*last)->next = new_node;
    *last = new_node;
    new_node->next = *first;
}

void delete_beginning(node** first,node** last){
    if(*first == NULL || *last == *first){
        *first = NULL;
        *last = NULL;
        return;
    }
    node* temp = *first;
    *first = (*first)->next;
    (*last)->next = *first;
    free(temp);
}

void delete_end(node** first,node** last){
    if(*first == NULL || *last == *first){
        *first = NULL;
        *last = NULL;
        return;
    }
    node* temp = *first;
    while(temp->next != *last) temp = temp->next;
    temp->next = *first;
    free(*last);
    *last = temp;
}

void display(node* first,node* last){
    node* temp = first;
    while(temp != last){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    if(first != NULL)printf("%d -> ",last->data);
    printf("NULL\n");
}

int main(){
    node *first = NULL, *last = NULL;
    int choice,e;
    printf("MENU\n");
    printf("Insert at end - 1\n");
    printf("Delete from beginning - 2\n");
    printf("Delete from end - 3\n");
    printf("Display - 4\n");
    printf("Exit - 5\n");
    while(1){
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter element: ");
            scanf("%d",&e);
            insert_end(&first,&last,e);
            break;
            
            case 2:
            delete_beginning(&first,&last);
            break;

            case 3:
            delete_end(&first,&last);
            break;

            case 4:
            display(first,last);
            break;

            case 5:
            return 0;

            default:
            printf("invalid input\n");
        }
    }

}