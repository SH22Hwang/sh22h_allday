#include <stdio.h>

int main()
{
    int num = 0;
    scanf("%d", &num);

    for (int i = 1; i <= num; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        for (int j = 0; j < 2 * (num - i); j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }

        printf("\n");
    }

    for (int i = num - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        for (int j = 0; j < 2 * (num - i); j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}