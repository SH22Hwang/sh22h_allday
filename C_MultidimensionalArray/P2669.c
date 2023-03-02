#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int table[105][105] = {0};

    for (int i = 0; i < 4; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        for (int x = x1; x < x2; x++)
        {
            for (int y = y1; y < y2; y++)
            {
                table[x][y] = 1;
            }
        }
    }

    int cnt = 0;

    for (int i = 0; i < 105; i++)
    {
        for (int j = 0; j < 105; j++)
        {
            if (table[i][j])
                cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}