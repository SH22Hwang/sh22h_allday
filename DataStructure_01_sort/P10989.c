#include <stdio.h>
#define MAX_SIZE 10001

int sort[MAX_SIZE] = {0};

int main(void)
{
    int num, temp;
    scanf("%d", &num);
    if (num == 1)
    {
        scanf("%d", &num);
        printf("%d", num);
        return 0;
    }

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &temp);
        sort[temp]++;
    }

    for (int j = 1; j < MAX_SIZE; j++)
    {
        for (int k = 0; k < sort[j]; k++)
            printf("%d\n", j);
    }

    return 0;
}