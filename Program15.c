//Write a program to represent an undirected graph using the adjacency matrix to implement the graph and perform the operations with menu-driven options for the following tasks: 1. Create graph 2. Insert an edge 3. Print Adjacency Matrix 4. List all vertices that are adjacent to a specified vertex. 6. Exit program.
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices = 0;
void createGraph() {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = 0;
        }
    }
    printf("Graph created with %d vertices.\n", numVertices);
}
void insertEdge() {
    int src, dest;
    printf("Enter source vertex: ");
    scanf("%d", &src);
    printf("Enter destination vertex: ");
    scanf("%d", &dest);
    if (src >= numVertices || dest >= numVertices) {
        printf("Invalid vertices. Please try again.\n");
        return;
    }
    graph[src][dest] = 1;
    graph[dest][src] = 1; 
    printf("Edge inserted between vertex %d and vertex %d.\n", src, dest);
}
void printAdjacencyMatrix() {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
void listAdjacentVertices() {
    int vertex;
    printf("Enter the vertex to list adjacent vertices: ");
    scanf("%d", &vertex);
    if (vertex >= numVertices) {
        printf("Invalid vertex. Please try again.\n");
        return;
    }
    printf("Adjacent vertices to vertex %d: ", vertex);
    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
int main() {
    int choice;
    while (1) {
        printf("\n--- Graph Operations Menu ---\n");
        printf("1. Create Graph\n");
        printf("2. Insert an Edge\n");
        printf("3. Print Adjacency Matrix\n");
        printf("4. List Adjacent Vertices\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createGraph();
                break;
            case 2:
                insertEdge();
                break;
            case 3:
                printAdjacencyMatrix();
                break;
            case 4:
                listAdjacentVertices();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
