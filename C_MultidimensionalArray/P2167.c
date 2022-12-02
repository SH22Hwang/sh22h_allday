#include <stdio.h>

#define MAX_SIZE 303

int main()
{
    int arr[MAX_SIZE][MAX_SIZE];

    int row, column;
    scanf("%d %d", &row, &column);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf(" %d", &arr[i][j]);
        }
    }

    int k;
    scanf("%d", &k);
    while (k--)
    {
        int sum = 0;
        int startrow, startcol, endrow, endcol; // (i, j)부터 (x, y)까지의 배열의 합 구하기
        scanf(" %d %d %d %d", &startrow, &startcol, &endrow, &endcol);

        startrow--;
        startcol--;

        for (int i = startrow; i < endrow; i++)
        {
            for (int j = startcol; j < endcol; j++)
            {
                sum += arr[i][j];
            }
        }

        printf("%d\n", sum);
    }

    return 0;
}