#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int row, column, cnt;
    int curr = 0, curc = 0;
    int i = 0, j = 0;
    scanf("%d %d", &row, &column);

    while (row > 0 || column > 0)
    {
        for (j = 0; j < column; j++)
        {
            printf("%d %d\n", i, j);
        }
        cnt++;
        row--;

        for (i = 0; i < row; i++)
        {
            printf("%d %d\n", i, j);
        }
        cnt++;
        column--;

        for (j = 0; j < column; j++)
        {
            printf("%d %d\n", i, j);
        }
        cnt++;
        row--;

        for (i = 0; i < row; i++)
        {
            printf("%d %d\n", i, j);
        }
        cnt++;
        column--;
    }

    printf("%d", cnt);
    return 0;
}