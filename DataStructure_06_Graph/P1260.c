#include <stdio.h>

#define MAX_SIZE 1001

int graph[MAX_SIZE][MAX_SIZE] = {0};
int visit[MAX_SIZE] = {0};
int node, edge, start_vertex;

void dfs(int v);
void bfs(int v);

int main()
{
    scanf("%d %d %d", &node, &edge, &start_vertex);

    int x, y;
    for (int i = 0; i < edge; i++)
    {
        scanf("%d %d", &x, &y);
        graph[x][y] = graph[y][x] = 1;
    }

    dfs(start_vertex);
    printf("\n");
    bfs(start_vertex);

    return 0;
}

// void dfs(int v) // stack, 재귀함수
// {
//     printf("%d ", v);
//     visit[v] = 1;
//     for (int i = 1; i <= node; i++)
//     {
//         if (visit[i] || graph[v][i] == 0)
//         {
//             continue;
//         }
//         dfs(i);
//     }
// }

void dfs(int v) // 재귀함수를 쓰지않는 스택
{
    int stack[100001] = {0};
    idx_top = -1;

    stack[++idx_top] = v;
    visit[v] = 1;
    while (idx_top >= 0)
    {
        printf("%d", v);
        v = stack[idx_top--];

        if (visit[v] == 0)
        {
            visit[v] = 1;
            for (int i = 0; i <)
                if (graph[v][i])
        }
        dfs(i);
    }

    visit[v] = 1;
}

void bfs(int v) // queue
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
        for (int i = 1; i <= node; i++)
        {
            if (!visit[i] || graph[v][i] == 0)
            {
                continue;
            }
            // q.push(i);
            q[rear++] = i;
            visit[i] = 0;
        }
    }
}