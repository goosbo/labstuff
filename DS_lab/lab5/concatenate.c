#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;

node* create_node(int data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}
void insert(node** head,node** tail, int data){
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
void display(node* head){
    node* temp = head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void concat(node** head2, node** tail1){
    (*tail1)->next = *head2;
    (*head2)->prev = *tail1;
}

int main(){
    node *head1=NULL,*head2=NULL,*tail1=NULL,*tail2=NULL;
    int s1,s2;
    printf("Enter size of 1st linked list: ");
    scanf("%d",&s1);
    printf("Enter elements: ");
    for(int i = 0; i < s1; i++){
        int x;
        scanf("%d",&x);
        insert(&head1,&tail1,x);
    }
    printf("Enter size of 2nd linked list: ");
    scanf("%d",&s2);
    printf("Enter elements: ");
    for(int i = 0; i < s2; i++){
        int x;
        scanf("%d",&x);
        insert(&head2,&tail2,x);
    }

    printf("Linked List 1 : ");
    display(head1);
    printf("Linked List 2 : ");
    display(head2);

    concat(&head2,&tail1);
    printf("Concatenated List: ");
    display(head1);
}
