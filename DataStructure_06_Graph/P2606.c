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
    int x, y;
    scanf("%d", &vertex);
    scanf("%d", &edge);
    for (int i = 0; i < edge; i++)
    {
        scanf("%d%d", &x, &y);
        map[x][y] = map[y][x] = 1;
    }
    bfs(1);
    printf("%d", result);
}
