#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int field[102][102] = {0};
    int result[101] = {0};

    int tc, x, y, w, h, min_x = 1002, min_y = 1002, max_x = 0, max_y = 0;
    scanf("%d", &tc);

    for (int paper = 1; paper <= tc; paper++)
    {
        scanf(" %d %d %d %d", &x, &y, &w, &h);
        for (int i = x; i < x + w; i++)
        {
            for (int j = y; j < y + h; j++)
            {
                field[i][j] = paper;
            }
        }

        if (min_x > x)
            min_x = x;

        if (min_y > y)
            min_y = y;

        if (max_x < x + w)
            max_x = x + w;

        if (max_y < y + h)
            max_y = y + h;
    }

    for (int i = min_x; i <= max_x; i++) // 1000대신 최소 최대 범위 구해야할 듯
    {
        for (int j = min_y; j <= max_y; j++)
        {
            result[field[i][j]]++;
        }
    }

    for (int i = 1; i <= tc; i++)
        printf("%d\n", result[i]);

    return 0;
}