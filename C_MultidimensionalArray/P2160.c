#include <stdio.h>
#include <string.h>

int main(void)
{
    int num = 0;
    scanf("%d", &num);

    char line[8];            // 임시로 받을 배열
    char pic[50][5][8] = {}; // 비교할 그림 최대 50개

    int cmp = 50; // 비슷한 그림 찾는 수
    int p1, p2;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf(" %s", &line);
            strcpy(pic[i][j], line);
        }

        for (int x = i - 1; x >= 0; x--) // 이전 그림
        {
            int temp = 0;
            for (int y = 0; y < 5; y++) // 이전 그림 row
            {
                for (int z = 0; z < 7; z++) // 이전 그림 column
                {
                    if (pic[i][y][z] != pic[x][y][z])
                    {
                        temp++;
                    }
                }
            }

            if (temp < cmp)
            {
                cmp = temp;
                p1 = x + 1, p2 = i + 1;
            }
        }
    }

    printf("%d %d", p1, p2);

    return 0;
}