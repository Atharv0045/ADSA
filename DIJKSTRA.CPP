#include <stdio.h>
#include <conio.h>

#define INF 9999
#define MAX 10

void dijkstra(int graph[MAX][MAX], int n, int start)
{
    int distance[MAX], visited[MAX];
    int i, count, u, v, min;

    for (i = 0; i < n; i++) {
        distance[i] = graph[start][i];
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;

    for (count = 1; count < n; count++) {
        min = INF;
        u = -1;

        for (i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < min) {
                min = distance[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (v = 0; v < n; v++) {
            if (!visited[v] &&
                graph[u][v] != INF &&
                distance[u] + graph[u][v] < distance[v]) {

                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", start + 1);

    for (i = 0; i < n; i++) {
        printf("To vertex %d = %d\n", i + 1, distance[i]);
    }
}

void main()
{
    int graph[MAX][MAX];
    int n, i, j, start;

    clrscr();

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    printf("(Enter 9999 if there is no edge)\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nEnter starting vertex (1-%d): ", n);
    scanf("%d", &start);

    dijkstra(graph, n, start - 1);

    getch();
}
