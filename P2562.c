#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int nums[10] = {
        0,
    };
    for (int i = 0; i < 9; i++)
    {
        int temp;
        scanf("%d", &temp);
        nums[i] = temp;
    }

    int max = -1, result;
    for (int i = 0; i < 9; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
            result = i + 1;
        }
    }

    printf("%d\n%d", max, result);
    return 0;
}