
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#define MAX 100

int parent[MAX];

struct Edge {
    int u, v, wt;
} edges[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->wt - ((struct Edge *)b)->wt;
}

int main() {
	system("color f0");
    int n, e, i, u, v, w, total = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    for (i = 0; i < e; i++) {
        printf("Enter edge %d (u v wt): ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].wt);
    }
    for (i = 0; i < n; i++)
        parent[i] = i;
    qsort(edges, e, sizeof(edges[0]), compare);
    printf("Edges in MST:\n");
    for (i = 0; i < e; i++) {
        u = find(edges[i].u);
        v = find(edges[i].v);
        if (u != v) {
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].wt);
            total += edges[i].wt;
            unionSet(u, v);
        }
    }
    printf("Total cost: %d\n", total);
    return 0;
}

