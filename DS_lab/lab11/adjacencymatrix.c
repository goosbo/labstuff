#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
    int adjMatrix[MAX][MAX];
    int numVertices;
    int isDirected;
} Graph;

void initGraph(Graph *g, int vertices, int isDirected) {
    g->numVertices = vertices;
    g->isDirected = isDirected;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int src, int dest) {
    if (src >= g->numVertices || dest >= g->numVertices || src < 0 || dest < 0) {
        printf("invalid vertex! vertices should be between 0 and %d\n", g->numVertices - 1);
        return;
    }
    g->adjMatrix[src][dest] = 1;
    if (!g->isDirected) g->adjMatrix[dest][src] = 1;
}

void displayGraph(Graph *g) {
    printf("\nAdjacency Matrix (%s Graph):\n", 
           g->isDirected ? "Directed" : "Undirected");
    
    printf("   ");
    for (int i = 0; i < g->numVertices; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < g->numVertices; i++) {
        printf("%2d ", i);
        for (int j = 0; j < g->numVertices; j++) {
            printf("%2d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void inputGraph(Graph *directedGraph, Graph *undirectedGraph) {
    int numEdges, src, dest;
    
    printf("\nEnter the number of edges: ");
    scanf("%d", &numEdges);
    
    printf("\nEnter edges (format: source destination):\n");
    printf("vertices should be between 0 and %d\n", directedGraph->numVertices - 1);
    
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(directedGraph, src, dest);
        addEdge(undirectedGraph, src, dest);
    }
}

int main() {
    Graph directedGraph, undirectedGraph;
    int vertices;
    
    printf("\nEnter the number of vertices (max %d): ", MAX);
    scanf("%d", &vertices);
    
    if (vertices <= 0 || vertices > MAX) {
        printf("Invalid number of vertices!\n");
        return 1;
    }
    
    initGraph(&directedGraph, vertices, 1);      
    initGraph(&undirectedGraph, vertices, 0);   
    
    inputGraph(&directedGraph, &undirectedGraph);
    
    displayGraph(&directedGraph);
    displayGraph(&undirectedGraph);
    
    return 0;
}