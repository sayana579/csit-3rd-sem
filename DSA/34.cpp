
#include <stdio.h>
#define INF 99
#define max 10

int minKey(int key[], int mstSet[], int n) {
    int min = INF, min_index;

    for (int v = 0; v < n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[max][max], int n) {
    printf("Edge \t\tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t\t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(int graph[max][max], int n) {
    int parent[max];
    int key[max];
    int mstSet[max];

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, n);
}

int main() {
    int graph[max][max], n;

    printf("Enter the number of vertices in the graph (max %d): ", max);
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use %d for no connection):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, n);
    return 0;
}
