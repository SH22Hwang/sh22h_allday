#include <stdio.h>
#define MAX_NUM 505

int main(void)
{
    int table[MAX_NUM][MAX_NUM] = {0};
    int dp[MAX_NUM][MAX_NUM] = {0};
    int num;
    scanf("%d", &num);

    // 입력
    for (int i = 1; i <= num; i++)
    {
        for (int j = 0; j < i; j++)
        {
            scanf("%d", &table[i][j]);
        }
    }

    // dp 테이블 끝 요소 채우기
    dp[1][0] = table[1][0];
    for (int i = 2; i <= num; i++)
    {
        dp[i][0] = dp[i - 1][0] + table[i][0];
        dp[i][i - 1] = dp[i - 1][i - 2] + table[i][i - 1];
    }

    // dp
    for (int i = 3; i <= num; i++)
    {
        for (int j = 1; j < num; j++)
        {
            int left = dp[i - 1][j - 1];
            int right = dp[i - 1][j];

            if (left <= right)
            {
                dp[i][j] = table[i][j] + right;
            }
            else
            {
                dp[i][j] = table[i][j] + left;
            }
        }
    }

    // 맨 마지막 줄 중 가장 큰 수
    int result = 0;
    for (int k = 0; k < num; k++)
    {
        if (result < dp[num][k])
            result = dp[num][k];
    }

    printf("%d", result);
    // 테스트
    // printf("====테스트====\n");
    // for (int i = 1; i < num + 1; i++)
    // {
    //     for (int j = 0; j < num; j++)
    //     {
    //         printf("%d ", dp[i][j]);
    //     }

    //     printf("\n");
    // }

    return 0;
}
