#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int get_dir(int d)
{
    return d < 3 ? d + 1 : 0;
}

int main()
{
    int table[MAX_SIZE][MAX_SIZE] = {0};
    int move_row[4] = {-1, 0, 1, 0}; // 위 → 오 → 아 → 왼
    int move_column[4] = {0, 1, 0, -1};

    int length, num;
    scanf("%d %d", &length, &num);

    int row = length / 2, column = length / 2, dir = 0;
    int start_row = row - 1, end_row = row + 1;
    int start_column = column - 1, end_column = column + 1;
    int res_x, res_y;

    int size = length * length;
    for (int i = 1; i < size + 1; i++)
    {
        table[row][column] = i;
        if (i == num)
        {
            res_x = row + 1;
            res_y = column + 1;
        }

        int x = row + move_row[dir];       // 이동할 곳
        int y = column + move_column[dir]; // 이동할 곳

        if (table[x][y] == 1 || x < start_row || y < start_column || x > end_row || y > end_column) // 끝에 닿으면 or 다 차면
        {
            dir = get_dir(dir);
            x = row + move_row[dir];       // 이동할 곳
            y = column + move_column[dir]; // 이동할 곳

            if (dir == 0)
            {
                start_row--, end_row++;
                start_column--, end_column++;
            }
        }

        row = x;
        column = y;
    }

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    printf("%d %d", res_x, res_y);

    return 0;
}