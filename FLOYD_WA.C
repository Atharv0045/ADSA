#include <stdio.h>
#include <conio.h>

#define INF 9999
#define MAX 20

void main()
{
    int graph[MAX][MAX], n;
    int i, j, k;

    clrscr();

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    printf("(Enter %d for INF/no edge)\n\n", INF);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    /* Floyd-Warshall Algorithm */
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    printf("\nAll-Pairs Shortest Path Matrix:\n\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }

    getch();
}
