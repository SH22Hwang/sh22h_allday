#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int visit[10][10] = {0};
    int m, n;
    scanf("%d %d", &m, &n);

    int start_m = 0, end_m = m, start_n = 0, end_n = n;
    int row = 0, column = 0;
    int cnt = 0, result = 0, brk = m * n;

    while (1)
    {
        for (column = start_n; column < end_n; column++)
        {
            visit[row][column] = 1;
            cnt++;
        }
        start_m++, column--;

        result++;
        if (cnt >= brk)
            break;

        for (row = start_m; row < end_m; row++)
        {
            visit[row][column] = 1;
            cnt++;
        }
        end_n--, row--;

        result++;
        if (cnt >= brk)
            break;

        for (column = end_n; column >= start_n; column--)
        {
            visit[row][column] = 1;
            cnt++;
        }
        end_m--, column++;

        result++;
        if (cnt >= brk)
            break;

        for (row = end_m; row >= start_m; row--)
        {
            visit[row][column] = 1;
            cnt++;
        }
        start_n++, column++;

        result++;
        if (cnt >= brk)
            break;
    }

    printf("%d", result);
    return 0;
}