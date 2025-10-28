#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int isDirected) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    
    if (!isDirected) {
        newNode = createNode(src);
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    }
}

void printGraph(struct Graph* graph, const char* type) {
    printf("\n%s Adjacency List\n", type);
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("%d: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void freeGraph(struct Graph* graph) {
    if (graph) {
        for (int v = 0; v < graph->numVertices; v++) {
            struct Node* temp = graph->adjLists[v];
            while (temp) {
                struct Node* toFree = temp;
                temp = temp->next;
                free(toFree);
            }
        }
        free(graph->adjLists);
        free(graph);
    }
}

int main() {
    int vertices, edges, src, dest;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    if (vertices <= 0) {
        printf("Invalid number of vertices!\n");
        return 1;
    }
    
    struct Graph* directedGraph = createGraph(vertices);
    struct Graph* undirectedGraph = createGraph(vertices);
    
    printf("\nEnter the number of edges: ");
    scanf("%d", &edges);
    
    if (edges < 0) {
        printf("Invalid number of edges!\n");
        freeGraph(directedGraph);
        freeGraph(undirectedGraph);
        return 1;
    }
    
    printf("\nEnter edges (source destination):\n");
    
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        
        if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
            printf("Invalid edge! Vertices must be between 0 and %d\n", vertices - 1);
            i--;
            continue;
        }
    
        addEdge(directedGraph, src, dest, 1); 
        addEdge(undirectedGraph, src, dest, 0);  
    }
    
    printGraph(directedGraph, "Directed");
    printGraph(undirectedGraph, "Undirected");
    freeGraph(directedGraph);
    freeGraph(undirectedGraph);
    
    return 0;
}