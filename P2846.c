#include <stdio.h>

int main()
{
    int nums[1000] = {
        0,
    };
    int N, temp1 = 0, temp2 = 0, ascent = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf(" %d", &nums[i]);

    for (int i = 0; i < N; i++)
    {
        temp1 = nums[i];
        temp2 = 0;
        if (nums[i + 1] > nums[i])
        {
            int j;
            for (j = i + 1; j <= N; j++)
            {
                if (nums[j] <= temp2)
                    break;
                else
                    temp2 = nums[j];
            }

            i = j - 1;
            if (temp2 - temp1 > ascent)
                ascent = temp2 - temp1;
        }
    }

    printf("%d", ascent);
    return 0;
}