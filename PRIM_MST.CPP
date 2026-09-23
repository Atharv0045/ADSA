#include <stdio.h>
#include <conio.h>

#define INF 9999

void main()
{
    int cost[10][10], visited[10];
    int n, i, j, edges = 0;
    int min, u = 0, v = 0;
    int total = 0;

    clrscr();

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    printf("(Enter 9999 for no edge)\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    /* Initially, no vertex is included */
    for (i = 0; i < n; i++)
        visited[i] = 0;

    /* Start from vertex 0 */
    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n - 1)
    {
        min = INF;

        /* Find minimum edge connecting visited to unvisited vertex */
        for (i = 0; i < n; i++)
        {
            if (visited[i] == 1)
            {
                for (j = 0; j < n; j++)
                {
                    if (visited[j] == 0 && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (min == INF)
        {
            printf("\nGraph is not connected.\n");
            break;
        }

        printf("%d - %d  =  %d\n", u + 1, v + 1, min);

        total = total + min;
        visited[v] = 1;
        edges++;
    }

    if (edges == n - 1)
        printf("\nMinimum cost = %d", total);

    getch();
}