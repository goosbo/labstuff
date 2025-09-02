#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;

node* create_node(int data){
    node* new_node = (node*)malloc(sizeof(node));
    if(!new_node){
        printf("memory allocation failed!");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

node* insert_before_val(node* head ,int val, int d){

    node* newnode = create_node(d);
    node *temp = head,*temp1;
    if(head->data == val){
        newnode->next = head;
        head = newnode;
        return head;
    }
    while(temp->data != val && temp->next != NULL){
        temp1 = temp;
        temp = temp ->next;
    }

    if(temp->data == val){
        temp1->next = newnode;
        newnode->next = temp;
    }
    else{
        printf("element not found with val!\n");
    }
    return head;

}

node* insert_after_val(node* head, int val, int d){

    node* newnode = create_node(d);
    node *temp = head;

    while(temp != NULL && temp->data != val )temp = temp->next;
    if(temp == NULL){
        printf("element not found with val!\n");
        return head;
    }
    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}

node* delete(node* head, int val){
    if(head == NULL) return head;
    node *temp = head, *temp1;
    while(temp->data != val && temp->next != NULL){
        temp1 = temp;
        temp = temp ->next;
    }
    if(temp == head) return NULL;
    temp1->next = temp->next;
    free(temp);
    return head;
}

void display(node* head){
    if(head == NULL){
        printf("linked list is empty!\n");
        return;
    }
    node* temp = head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

node* reverse(node* head) {
    if (head == NULL) return head;

    node* prev = NULL;
    node* curr = head;
    node* next = NULL;

    while (curr != NULL) {
        next = curr->next;  
        curr->next = prev;  
        prev = curr;        
        curr = next;      
    }

    head = prev;
    return head;
}

int len(node* head){
    node* temp = head;
    int l = 0;
    while(temp != NULL){
        l++;
        temp = temp->next;
    }
    return l;
}

node* bubble_sort(node* head){
    if(head == NULL || head->next == NULL) return head;
    int l = len(head);
    for(int i = 0; i < l-1; i++){
        node* temp = head, *prev = NULL;
        while(temp->next != NULL){
            if(temp->data > temp->next->data){
                if(temp == head){
                    node* nxt = temp->next;
                    temp->next = nxt->next;
                    nxt->next = temp;
                    head = nxt;
                    prev = head;
                }
                else{
                    node* nxt = temp->next;
                    prev->next = nxt;
                    temp->next = nxt->next;
                    nxt->next = temp;
                    prev = nxt;
                }

            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }
    }
    return head;
}

void delete_alternate(node* head){
    if(head == NULL || head->next == NULL) return;
    node* temp = head;

    while(temp->next->next != NULL){
        node* del = temp->next;
        temp->next = temp->next->next;
        temp = temp->next;
        free(del);
        if(temp->next == NULL) return;
    }
}

node* insert_sorted(node* head,int v){
    node* temp = head,*temp1;
    node* new_node = create_node(v);
    while(temp != NULL && temp->data < v){
        temp1 = temp;
        temp = temp->next;
    }
    if(temp == head){
        new_node->next = head;
        head = new_node;
        return head;
    }
    temp1->next = new_node;
    new_node->next = temp;
    return head;
}

node* insert_beginning(node* head,int v){
    node* new_node = create_node(v);
    if(head == NULL){
        head = new_node;
        return head;
    }
    new_node->next = head;
    head = new_node;
    return head;
}

node* insert_end(node* head, int v){

    node* temp = head,*new_node = create_node(v);
    if(head == NULL){
        head = new_node;
        return head;
    }
    while(temp->next != NULL) temp = temp->next;
    temp->next = new_node;
    new_node->next = NULL;
    return head;
}

int main(){
    node* head = NULL;
    int c,d,val;
    printf("\nMENU\n");
    printf("1. Insert a node at the beginning\n");
    printf("2. Insert a node at the end\n");
    printf("3. Insert an element before another element\n");
    printf("4. Insert an element after another element\n");
    printf("5. Delete an element\n");
    printf("6. Display\n");
    printf("7. Reverse\n");
    printf("8. Sort\n");
    printf("9. Delete alternate elements\n");
    printf("10. Insert element into sorted linked list\n");
    printf("11. Exit\n");
    while(1){
        
        printf("Enter your choice: ");
        scanf("%d",&c);

        switch (c)
        {
        case 1:
            printf("Enter element to be inserted: ");
            scanf("%d",&d);
            head = insert_beginning(head,d);
            break;
        
        case 2:
            printf("Enter element to be inserted: ");
            scanf("%d",&d);
            head = insert_end(head,d);
            break;

        case 3:
            printf("Enter element to be inserted: ");
            scanf("%d",&d);
            printf("Enter element it should be inserted before: ");
            scanf("%d",&val);
            head = insert_before_val(head,val,d);
            break;

        case 4:
            printf("Enter element to be inserted: ");
            scanf("%d",&d);
            printf("Enter element it should be inserted after: ");
            scanf("%d",&val);
            head = insert_after_val(head,val,d);
            break;

        case 5:
            printf("Enter element to be deleted: ");
            scanf("%d",&d);
            head = delete(head,d);
            break;

        case 6:
            display(head);
            break;

        case 7:
            head = reverse(head);
            break;
        
        case 8:
            head = bubble_sort(head);
            break;

        case 9:
            delete_alternate(head);
            break;

        case 10:
            printf("Enter element to be inserted: ");
            scanf("%d",&d);
            head = insert_sorted(head,d);
            break;

        case 11:
            return 0;
            
        default:
            printf("invalid input\n");
        }
        
    }
    return 0;
}
