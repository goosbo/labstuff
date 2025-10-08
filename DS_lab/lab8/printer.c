#include "stdio.h"
#include "time.h"
#include "string.h"
#define MAX 100

typedef struct task{
    int docID;
    char name[MAX];
}task;

typedef struct queue{
    task tasks[MAX];
    int front,rear;
}queue;


void enqueue(queue* q,task t){
    if(q->rear == MAX-1){
        printf("queue is full\n");
        return;
    }
    if(q->front == -1)++q->front;
    q->tasks[++q->rear] = t;
}

task dequeue(queue* q){
    if(q->front == -1){
        printf("queue is empty\n");
        task empty = {-1,"empty"};
        return empty;        
    }
    task temp = q->tasks[q->front++];
    if(q->front > q->rear){
        q->front = -1;
        q->rear = -1;
    }
    return temp;
}

int main(){
    queue q;
    q.front = -1;
    q.rear = -1;
    srand(time(0));
    int njobs;
    printf("Enter number of printing jobs: ");
    scanf("%d",&njobs);
    for(int i = 0; i < njobs;i++){
        task t;
        t.docID = rand() % 1000;
        snprintf(t.name,MAX,"Document_%d",t.docID);
        printf("Print job arrived: %s\n",t.name);
        enqueue(&q,t);
    }
    printf("processing print jobs....\n");
    for(int i = 0; i < njobs;i++){
        task t = dequeue(&q);
        printf("Processed %s\n",t.name);
    }
    return 0;
}
