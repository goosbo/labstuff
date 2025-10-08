#include "stdio.h"
#define MAX 10

typedef struct queue{
    int q[MAX],front,rear;
}queue;

void enqueue(queue *q,int val){
    if((q->rear+1)%MAX == q->front%MAX){
        printf("queue is full\n");
        return;
    }
    if(q->front == -1)++q->front;
    q->q[(++q->rear)%MAX] = val;
}

int dequeue(queue* q){
    if(q->front == -1){
        printf("queue is empty\n");
        return -1;       
    }
    int temp = q->q[(q->front)%MAX];
    if(q->front%MAX == q->rear%MAX){
        q->front = -1;
        q->rear = -1;
    }
    else q->front++;
    return temp;
}

void print(queue q){
    int i = q.front%MAX;
    if(i == -1)return;
    printf("queue: ");
    while(i%MAX!=q.rear%MAX)printf("%d ",q.q[i++%MAX]);
    printf("%d\n",q.q[q.rear%MAX]);
}

int main(){
    int choice,n;
    queue q;
    q.front = -1;
    q.rear = -1;
    printf("MENU\n1.Enqueue\n2.Dequeue\n3.Display\n4.EXIT\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter number: ");
            scanf("%d",&n);
            enqueue(&q,n);
            break;
        case 2:
            n = dequeue(&q);
            printf("Dequeued %d\n",n);
            break;
        case 3:
            print(q);
            break;
        case 4:
        return 0;
        default:
            printf("invalid input\n");
            break;
        }
    }
}