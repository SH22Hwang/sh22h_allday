#include <stdio.h>

int main()
{
    int result[4] = {0};
    int max = 0, gon, goff;

    scanf("%d %d", &goff, &gon);
    result[0] += gon;

    for (int i = 1; i < 4; i++)
    {
        result[i] = result[i - 1];

        scanf("%d %d", &goff, &gon);
        result[i] += gon;
        result[i] -= goff;
    }

    for (int i = 0; i < 4; i++)
    {
        if (max < result[i])
            max = result[i];
    }

    printf("%d", max);

    return 0;
}