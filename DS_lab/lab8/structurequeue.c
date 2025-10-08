#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct patient{
    char name[100];
    int age;
    int id;
    struct patient* next;
}patient;

typedef struct queue{
    patient* top;
    patient* rear;
}queue;

void enqueue(queue **q,char name[],int age,int id){
    patient* newnode = (patient*)malloc(sizeof(patient));
    if(newnode == NULL){
        printf("queue is full\n");
        return;
    }
    strcpy(newnode->name,name);
    newnode->age = age;
    newnode->id = id;
    if((*q)->top == NULL){
        (*q)->top = newnode;
        (*q)->rear = newnode;
    }
    else{
        (*q)->rear->next = newnode;
        (*q)->rear = (*q)->rear->next;
    }
}

patient* dequeue(queue** q){
    if((*q)->top  == NULL){
        printf("queue is empty\n");
        return NULL;
    }
    patient* temp = (*q)->top ;
    if((*q)->top == (*q)->rear){
        (*q)->top  = NULL;
        (*q)->rear = NULL;
    }
    else (*q)->top  = (*q)->top->next;
    return temp;
}

void print(queue* q){
    patient* temp = q->top ;
    if(temp == NULL)return;
    while(temp!=q->rear){
        printf("(%s,%d,%d)->",temp->name,temp->age,temp->id);
        temp = temp->next;
    }
    printf("(%s,%d,%d)\n",q->rear->name,q->rear->age,q->rear->id);
}

int main(){
    int choice,age,id;
    char name[100];
    patient *t;
    queue *q = (queue*)malloc(sizeof(queue));
    q->top = NULL;
    q->rear = NULL;

    printf("MENU\n1.Enqueue\n2.Dequeue\n3.Display\n4.EXIT\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter name,age and id: ");
            scanf("%*c%s",name);
            scanf("%d %d",&age,&id);
            enqueue(&q,name,age,id);
            break;
        case 2:
            t = dequeue(&q);
            printf("Dequeued (%s,%d,%d)\n",t->name,t->age,t->id);
            break;
        case 3:
            print(q);
            break;
        case 4:
        return 0;
        default:
            printf("invalid input\n");
            return 1;
        }
    }
}