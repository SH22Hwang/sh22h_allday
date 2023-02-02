#include <stdio.h>

int N, M, V;
int map[1001][1001];

int visit[1001];
void dfs(int v)
{
    printf("%d ", v);
    visit[v] = 1;
    for (int i = 1; i <= N; i++)
    {
        if (visit[i] || map[v][i] == 0)
        {
            continue;
        }
        dfs(i);
    }
}
void bfs(int v)
{
    // queue<int> q;
    // q.push(v);
    int q[100001];
    int front = 0, rear = 0;
    q[rear++] = v;
    visit[v] = 0;
    while (front < rear)
    {
        // v = q.front();
        v = q[front++];
        printf("%d ", v);
        // q.pop();
        for (int i = 1; i <= N; i++)
        {
            if (!visit[i] || map[v][i] == 0)
            {
                continue;
            }
            // q.push(i);
            q[rear++] = i;
            visit[i] = 0;
        }
    }
}

int main()
{
    int x, y;
    scanf("%d%d%d", &N, &M, &V);
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d", &x, &y);
        map[x][y] = map[y][x] = 1;
    }
    dfs(V);
    printf("\n");
    bfs(V);
}
