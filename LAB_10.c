#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_BOOKS 3
struct Edge {
    int src, dest, distance;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;

    graph->edge = (struct Edge*)malloc(graph->E * sizeof(struct Edge));

    return graph;
}

int minDistance(int distance[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < MAX_BOOKS; v++) {
        if (mstSet[v] == 0 && distance[v] < min) {
            min = distance[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[MAX_BOOKS][MAX_BOOKS]) {
    printf("Minimum Spanning Tree:\n");
    printf("Book \tDistance\n");
    for (int i = 1; i < MAX_BOOKS; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[MAX_BOOKS][MAX_BOOKS]) {
    int parent[MAX_BOOKS];
    int distance[MAX_BOOKS];
    int mstSet[MAX_BOOKS];

    for (int i = 0; i < MAX_BOOKS; i++) {
        distance[i] = INT_MAX;
        mstSet[i] = 0;
    }

    distance[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < MAX_BOOKS - 1; count++) {
        int u = minDistance(distance, mstSet);

        mstSet[u] = 1;

        for (int v = 0; v < MAX_BOOKS; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < distance[v]) {
                parent[v] = u;
                distance[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int myComp(const void* a, const void* b) {
    return ((struct Edge*)a)->distance - ((struct Edge*)b)->distance;
}

int main() {
    int bookDistances[MAX_BOOKS][MAX_BOOKS];
    int choice;

    printf("Enter the distances between books (0 for no connection):\n");
    for (int i = 0; i < MAX_BOOKS; i++) {
        // printf("Book");
        for (int j = 0; j < MAX_BOOKS; j++) {
            scanf("%d", &bookDistances[i][j]);
        }
    }

    struct Graph* userGraph = createGraph(MAX_BOOKS, MAX_BOOKS * (MAX_BOOKS - 1) / 2);

    int k = 0;
    for (int i = 0; i < MAX_BOOKS; i++) {
        for (int j = i + 1; j < MAX_BOOKS; j++) {
            userGraph->edge[k].src = i;
            userGraph->edge[k].dest = j;
            userGraph->edge[k].distance = bookDistances[i][j];
            k++;
        }
    }

    printf("Choose the MST algorithm:\n");
    printf("1. Prim's Algorithm\n");
    printf("2. Kruskal's Algorithm\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            primMST(bookDistances);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}