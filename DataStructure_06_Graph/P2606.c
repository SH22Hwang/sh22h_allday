#include <stdio.h>

int vertex, edge;
int result = 0;
int map[1001][1001] = {0};

int visit[1001] = {0};

void bfs(int v) // queue
{
    int q[100001];
    int front = 0, rear = 0;

    q[rear++] = v;
    visit[v] = 1;
    while (front < rear)
    {
        v = q[front++];
        for (int i = 1; i <= vertex; i++)
        {
            if (visit[i] || map[v][i] == 0)
            {
                continue;
            }

            q[rear++] = i;
            visit[i] = 1;
            result++;
        }
    }
}

int main()
{
    scanf("%d", &edge);
    vertex = 0;

    for (int i = 0; i < edge; i++)
    {
        char temp[30];
        scanf("%s", temp);
        for (int j = 0; j < edge; j++)
        {
            temp[j]
        }
    }
    bfs(1);
    printf("%d", result);
}
