#include <stdio.h>

#define MAX_LEN 51

int field[MAX_LEN][MAX_LEN] = {0}, visit[MAX_LEN][MAX_LEN] = {0}; // 배추밭, 방문

int dy[] = {1, -1, 0, 0}; // 위 아래 오른쪽 왼쪽 이동
int dx[] = {0, 0, 1, -1};
int field_garo, field_sero, cabbage_num;

void dfs(int ay, int ax);

int main(void)
{
    int tc; // 테스트케이스의 수
    scanf("%d", &tc);
    while (tc--)
    {
        int worm_num = 0; // 지렁이의 수
        for (int y = 0; y < MAX_LEN; y++)
        {
            for (int x = 0; x < MAX_LEN; x++)
            {
                field[y][x] = visit[y][x] = 0;
            }
        }

        scanf("%d %d %d", &field_garo, &field_sero, &cabbage_num);
        for (int i = 0; i < cabbage_num; i++)
        {
            int tempy, tempx;
            scanf("%d %d", &tempx, &tempy);
            field[tempy][tempx] = 1;
        }

        for (int y = 0; y < field_sero; y++)
        {
            for (int x = 0; x < field_garo; x++)
            {
                if (!visit[y][x] && field[y][x])
                {
                    visit[y][x] = 1;
                    worm_num++;
                    dfs(y, x);
                }
            }
        }

        printf("%d\n", worm_num);
    }

    return 0;
}

void dfs(int ay, int ax)
{
    for (int i = 0; i < 4; i++)
    {
        int y = ay + dy[i];
        int x = ax + dx[i];
        if (y >= 0 && y < field_sero && x >= 0 && x < field_garo && !visit[y][x] && field[y][x])
        {
            visit[y][x] = 1;
            dfs(y, x);
        }
    }
}