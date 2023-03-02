#include <stdio.h>
#include <string.h>

char chessboard[55][55];

int repaint(char flag, int start_row, int start_col)
{
    int cnt = 0;
    char check = flag;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (check != chessboard[start_row + i][start_col + j]) // 원래 있어야 할 check와 다르면
                cnt++;                                             // 카운트

            // check == 'W' ? check = 'B' : check = 'W'; // check 바꾸기
            if (check == 'W')
                check = 'B';
            else
                check = 'W';
        }

        if (flag == 'W') // 처음 나온 색에 따라 반전
        {
            check = 'B';
            flag = 'B';
        }
        else
        {
            check = 'W';
            flag = 'W';
        }
    }

    return cnt;
}

int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    int res = m * n;

    for (int i = 0; i < m; i++)
        scanf(" %s", chessboard[i]);

    for (int i = 0; i < m - 7; i++)
    {
        for (int j = 0; j < n - 7; j++)
        {
            int cnt_w = repaint('W', i, j);
            int cnt_b = repaint('B', i, j);

            if (cnt_w < res)
                res = cnt_w;
            if (cnt_b < res)
                res = cnt_b;
        }
    }

    printf("%d", res);

    return 0;
}