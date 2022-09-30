#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num = 0;
    scanf("%d", &num);

    for (int i = 1; i < num; i++)
    {
        for (int j = num; j > i; j--)
        {
            printf(" ");
        }

        if (i > 1 && i < num)
        {
            printf("*");
            for (int j = 0; j < 2 * (i - 1) - 1; j++)
                printf(" ");
            printf("*");
        }
        else
        {
            printf("*");
        }

        printf("\n");
    }

    for (int i = 0; i < 2 * num - 1; i++)
        printf("*");

    return 0;
}