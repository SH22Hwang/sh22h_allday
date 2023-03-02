#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int vertex, edge;
int result = 0;
int map[25][25] = {0}, visit[25][25] = {0}, apt[500];

int dy[4] = {1, -1, 0, 0}; // 위 아래 오른쪽 왼쪽
int dx[4] = {0, 0, 1, -1};
int apart_num, cnt, N, K;

void dfs(int ay, int ax)
{
    for (int i = 0; i < 4; i++)
    {
        int y = ay + dy[i];
        int x = ax + dx[i];
        if (y >= 0 && y < N && x >= 0 && x < N && !visit[y][x] && map[y][x] == 1)
        {
            visit[y][x] = 1;
            cnt++;
            dfs(y, x);
        }
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visit[i][j] && map[i][j] == 1)
            {
                visit[i][j] = 1;
                apart_num++; // 아파트의 수
                cnt++;       // 세대 수
                dfs(i, j);
                apt[K++] = cnt;
                cnt = 0;
            }
        }
    }

    sort(apt, apt + K); // C++ 함수
    printf("%d\n", apart_num);
    for (int i = 0; i < K; i++)
    {
        printf("%d\n", apt[i]);
    }

    return 0;
}
