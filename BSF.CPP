#include <stdio.h>
#include <conio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int n;

void enqueue(int vertex)
{
    if (rear == MAX - 1)
        return;

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = vertex;
}

int dequeue()
{
    int vertex;

    if (front == -1 || front > rear)
        return -1;

    vertex = queue[front];
    front++;

    return vertex;
}

void BFS(int start)
{
    int i, vertex;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front <= rear)
    {
        vertex = dequeue();
        printf("%d ", vertex);

        for (i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

void main()
{
    int i, j, start;

    clrscr();

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    BFS(start);

    getch();
}