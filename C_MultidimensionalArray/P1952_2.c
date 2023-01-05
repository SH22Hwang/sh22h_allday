#include <stdio.h>

int get_dir(int d)
{
    return d < 3 ? d + 1 : 0;
}

int main()
{
    int visit[105][105] = {0};
    int move_row[4] = {0, 1, 0, -1}; // 오 → 아 → 왼 → 위
    int move_column[4] = {1, 0, -1, 0};

    int m, n;
    scanf("%d %d", &m, &n);

    int row = 0, column = 0, dir = 0, result = 0;

    while (1)
    {
        if (visit[row][column] == 1)
            break;
        visit[row][column] = 1;

        int x = row + move_row[dir];       // 이동할 곳
        int y = column + move_column[dir]; // 이동할 곳

        if (visit[x][y] == 1 || x < 0 || y < 0 || x >= m || y >= n) // 끝에 닿으면 or 다 차면
        {
            dir = get_dir(dir);
            x = row + move_row[dir];       // 이동할 곳
            y = column + move_column[dir]; // 이동할 곳
            result++;
        }

        row = x;
        column = y;
    }

    printf("%d", result - 1);
    return 0;
}