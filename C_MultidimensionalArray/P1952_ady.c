#include <stdio.h>

int visit[105][105];
int N, M;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
// 3 -> 1, 1 -> 2, 2 -> 0, 0 -> 3
// 오 -> 아, 아 -> 왼, 왼 -> 위 , 위 -> 오

int get_dir(int d)
{
    if (d == 3 || d == 2)
        return (d + 2) % 4;
    else
        return 3 - d;
}

int main()
{

    scanf("%d %d", &M, &N);

    int x = 0, y = 0;
    int dir = 3;
    int ans = 0;

    while (1)
    {
        if (visit[x][y] == 1)
            break;

        visit[x][y] = 1;

        int xx = x + dx[dir];
        int yy = y + dy[dir];

        if (visit[xx][yy] == 1 || xx < 0 || yy < 0 || xx >= M || yy >= N)
        {
            dir = get_dir(dir);
            xx = x + dx[dir];
            yy = y + dy[dir];
            ans++;
        }

        x = xx;
        y = yy;
    }

    printf("%d\n", ans - 1);

    return 0;
}
