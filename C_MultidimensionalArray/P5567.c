/**
 * @file P5567.c
 * @author ghkd3531
 * @brief boj 5567번 결혼식... bfs로 깊이 2까지의 요소 수 구하기?
 * @date 2023-03-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>

#define MAX_SIZE 10005

int vertex, edge;
int table[505][505] = {0};
int visit[MAX_SIZE] = {0};
int queue[MAX_SIZE];
int level[MAX_SIZE] = {0}; // ChatGPT의 도움!
int front = 0, rear = 0;

void addEdge(int n1, int n2);
void bfs(int v, int depthLimit); // 깊이 제한

int main()
{
    scanf("%d %d", &vertex, &edge); // 동기의 수, 리스트의 길이

    for (int i = 0; i < edge; i++)
    {
        int f1, f2;
        scanf("%d %d", &f1, &f2);
        addEdge(f1, f2);
    }

    bfs(1, 2); // 1부터 bfs, 깊이 제한 2

    int cnt = 0;
    for (int i = 2; i <= vertex; i++) // 자기자신(1) 제외
    {
        if (0 < level[i])
            cnt++;
    }

    printf("%d", cnt);

    return 0;
}

void addEdge(int n1, int n2)
{
    table[n1][n2] = table[n2][n1] = 1;
}

void bfs(int v, int depthLimit)
{
    int current; // 현재 방문 노드
    queue[rear++] = v;
    visit[v] = 1;
    level[v] = 0;

    while (front < rear)
    {
        current = queue[front++];

        if (level[current] == depthLimit) // 깊이 제한: 2
        {
            continue;
        }

        for (int i = 1; i <= vertex; i++)
        {
            if (visit[i] || !table[current][i])
            {
                continue;
            }

            queue[rear++] = i;
            visit[i] = 1;
            level[i] = level[current] + 1;
        }
    }
}