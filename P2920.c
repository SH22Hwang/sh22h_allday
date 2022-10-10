#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int nums[8] = {
        0,
    };
    int flag = 0; // 1: mixed, 2: ascending 3: descending

    for (int i = 0; i < 8; i++)
    {
        scanf(" %d", &nums[i]);
    }

    if (nums[0] == 1)
    {
        flag = 2;

        for (int i = 0; i < 8; i++)
        {
            if (i + 1 != nums[i])
            {
                flag = 1;
                break;
            }
        }
    }
    else if (nums[0] == 8)
    {
        flag = 3;

        for (int i = 0; i < 8; i++)
        {
            if (8 - i != nums[i])
            {
                flag = 1;
                break;
            }
        }
    }
    else
        flag = 1;

    if (flag == 1)
        printf("mixed");
    else if (flag == 2)
        printf("ascending");
    else if (flag == 3)
        printf("descending");

    return 0;
}