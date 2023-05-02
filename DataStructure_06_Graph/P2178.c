#include <stdio.h>

#define MAX_SIZE 1001

typedef struct _node
{
    int x;
    int y;
} node;

int vertex, edge, garo, sero;
char map[MAX_SIZE][MAX_SIZE] = {0};
int dy[] = {1, -1, 0, 0}; // 위 아래 오른쪽 왼쪽 이동
int dx[] = {0, 0, 1, -1};

int bfs(int y, int x);

int main()
{
    scanf("%d %d", &sero, &garo);
    vertex = garo * sero;

    for (int i = 0; i < sero; i++)
    {
        scanf(" %s", &map[i]);
    }

    printf("%d", bfs(0, 0));
}

int bfs(int y, int x)
{
    node q[100001], v = {y, x};
    int front = 0, rear = 0;
    q[rear++] = v; // q에 v집어넣음

    while (front < rear)
    {
        v = q[front++];

        for (int i = 0; i < 4; i++)
        {
            node v_next = {v.x + dx[i], v.y + dx[i]}; // 새로운 노드, dxdy 이동순서에 따라 정의

            if (v_next.y >= 0 && v_next.y < sero && v_next.x >= 0 && v_next.x < garo && map[v_next.y][v_next.x])
            {
                map[v_next.y][v_next.x] = map[v.y][v.x] + 1; // 이전 노드보다 1 많음
            }
            q[rear++] = v_next; // 큐에 새로운 노드 삽입
        }
    }

    return map[sero - 1][garo - 1]; // 지나간 칸 출력
}