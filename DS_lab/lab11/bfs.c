#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue* q) {
    return q->rear == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

void BFS(int adjMatrix[MAX][MAX], int numVertices, int startVertex) {
    Queue* q = createQueue();
    int visited[MAX] = {0};
    
    printf("\nBFS Traversal starting from vertex %d: ", startVertex);
    
    visited[startVertex] = 1;
    enqueue(q, startVertex);
    
    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);
        
        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    printf("\n");
    free(q);
}

int main() {
    int numVertices, numEdges;
    int adjMatrix[MAX][MAX] = {0};
    int startVertex;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    
    if (numVertices <= 0 || numVertices > MAX) {
        printf("Invalid number of vertices!\n");
        return 1;
    }
    
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    
    printf("\nEnter the edges (format: source destination):\n");
    
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        
        if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
            printf("Invalid vertices! Please enter again.\n");
            i--;
            continue;
        }
        
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }
    
    printf("\nAdjacency Matrix:\n");
    printf("   ");
    for (int i = 0; i < numVertices; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < numVertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
    
    printf("\nEnter the starting vertex for BFS: ");
    scanf("%d", &startVertex);
    
    if (startVertex < 0 || startVertex >= numVertices) {
        printf("Invalid starting vertex!\n");
        return 1;
    }
    
    BFS(adjMatrix, numVertices, startVertex);
    return 0;
}