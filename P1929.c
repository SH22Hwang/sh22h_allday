#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000000

int main()
{
    int nums[1000] = {
        1,
        1,
        0,
    }; // 0이면 소수 1이면 소수 아님. 0으로 초기화

    int m, n;
    scanf("%d %d", &m, &n);

    for (int i = 2; i < (int)sqrt(n) + 1; i++)
    {
        if (!nums[i])
        {
            for (int j = i + i; j <= n; j += i)
            {
                nums[j] = 1;
            }
        }
    }

    if (m < 2)
        m = 2;

    for (int k = m; k <= n; k++)
    {
        if (!nums[k])
            printf("%d\n", k);
    }

    return 0;
}