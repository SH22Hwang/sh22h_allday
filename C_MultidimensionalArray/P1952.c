#include <stdio.h>

int main()
{
    int visit[10][10] = {0};
    int m, n;
    scanf("%d %d", &m, &n);

    int start_m = 0, end_m = m, start_n = 0, end_n = n;
    int row = 0, column = 0;
    int cnt = 0, result = 0, end_num = m * n, brk = 0;

    while (1)
    {
        for (column = start_n; column < end_n; column++)
        {
            visit[row][column] = 1;
            cnt++;
            if (cnt >= end_num)
                brk = 1;
        }

        if (brk)
            break;
        else
            start_m++, column--;
        result++;

        for (row = start_m; row < end_m; row++)
        {
            visit[row][column] = 1;
            cnt++;
            if (cnt >= end_num)
                brk = 1;
        }
        if (brk)
            break;
        else
            start_m++, column--;
        result++;

        for (column = end_n; column >= start_n; column--)
        {
            visit[row][column] = 1;
            cnt++;
            if (cnt >= end_num)
                brk = 1;
        }
        if (brk)
            break;
        else
            start_m++, column--;
        result++;

        for (row = end_m; row >= start_m; row--)
        {
            visit[row][column] = 1;
            cnt++;
            if (cnt >= end_num)
                brk = 1;
        }
        if (brk)
            break;
        else
            start_m++, column--;
        result++;
    }

    printf("%d", result);
    return 0;
}