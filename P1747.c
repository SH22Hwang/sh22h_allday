#include <stdio.h>
#include <math.h>

#define MAX_SIZE 1100

int main()
{
    int nums[MAX_SIZE] = {
        1,
        1,
        0,
    };

    int n, pal[7];
    scanf("%d", &n);

    // 소수 구하기
    for (int i = 2; i < (int)sqrt(MAX_SIZE) + 1; i++)
    {
        if (!nums[i])
        {
            for (int j = i + i; j <= MAX_SIZE; j += i)
                nums[j] = 1;
        }
    }

    if (n < 2)
        n = 2;

    // 찾은 소수 중에서 펠린드롬 수 구하기
    for (int k = n; k <= MAX_SIZE; k++)
    {
        // 소수일 때
        if (!nums[k])
        {
            int j, temp = k, flag = 1;
            for (j = 0; temp > 0; j++)
            {
                pal[j] = temp % 10;
                temp /= 10;
            }

            for (int i = 0; i < j / 2 + 1; i++)
            {
                if (pal[i] != pal[j - i - 1])
                {
                    flag = 0; // 펠린드롬 수가 아니면 flag: 0
                    break;
                }
            }

            if (flag) // 펠린드롬 수이면 출력하고 종료
            {
                printf("%d\n", k);
                break;
            }
        }
    }

    return 0;
}