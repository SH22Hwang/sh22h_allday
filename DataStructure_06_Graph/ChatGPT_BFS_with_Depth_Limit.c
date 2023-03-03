#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

int adjMatrix[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE];
int queue[MAX_SIZE];
int front = -1, rear = -1;

void bfs(int startNode, int depthLimit)
{
    int i, current;
    int level[MAX_SIZE] = {0}; // to keep track of the level of each node
    visited[startNode] = true;
    queue[++rear] = startNode;
    level[startNode] = 0;
    while (front != rear)
    {
        current = queue[++front];
        printf("%d ", current);
        if (level[current] == depthLimit)
        {
            continue;
        }
        for (i = 0; i < MAX_SIZE; i++)
        {
            if (adjMatrix[current][i] && !visited[i])
            {
                visited[i] = true;
                queue[++rear] = i;
                level[i] = level[current] + 1;
            }
        }
    }
}

int main()
{
    int n, e, i, j, startNode, depthLimit;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    printf("Enter the edges:\n");
    for (i = 0; i < e; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        adjMatrix[a][b] = adjMatrix[b][a] = 1;
    }
    printf("Enter the starting node: ");
    scanf("%d", &startNode);
    printf("Enter the depth limit: ");
    scanf("%d", &depthLimit);
    printf("BFS Traversal:\n");
    bfs(startNode, depthLimit);
    return 0;
}
