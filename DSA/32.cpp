
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#define MAX 100

int adj[MAX][MAX], visited[MAX];
int n;

void createGraph() {
    int edges, i, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for (i = 0; i < edges; i++) {
    printf("Enter edge %d: ", i + 1);
    scanf("%d %d", &u, &v);
    adj[u][v] = 1;
    adj[v][u] = 1;
}
}

void printAdjMatrix() {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i])
            DFS(i);
    }
}

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

void resetVisited() {
    for (int i = 0; i < n; i++) visited[i] = 0;
}

int main() {
	system("color f0");
    createGraph();

    printAdjMatrix();
 printf("\n");
    printf("DFS starting from vertex 0: ");
    resetVisited();
    DFS(0);
 printf("\n");
    printf("\nBFS starting from vertex 0: ");
    resetVisited();
    BFS(0);

    return 0;
}


