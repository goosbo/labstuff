#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;

Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    s->top++;
    s->items[s->top] = value;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        return -1;
    }
    int item = s->items[s->top];
    s->top--;
    return item;
}

void dfs(int adjMatrix[MAX][MAX], int numVertices, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            dfs(adjMatrix, numVertices, i, visited);
        }
    }
}

int main() {
    int numVertices, numEdges;
    int adjMatrix[MAX][MAX] = {0};
    int startVertex, choice;
    int visited[MAX] = {0};
    
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
    
    printf("\nEnter the starting vertex for DFS: ");
    scanf("%d", &startVertex);
    
    if (startVertex < 0 || startVertex >= numVertices) {
        printf("Invalid starting vertex!\n");
        return 1;
    }
    
    printf("\nDFS Traversal starting from vertex %d: ", startVertex);
    dfs(adjMatrix, numVertices, startVertex, visited);
    printf("\n");
    
    return 0;
}