#include <stdio.h>

int main(void)
{
    unsigned long long int n, gaus = 0;

    scanf("%llu", &n);

    // for (i = 1; i <= n; i++)
    // {
    //     if (n >= (i * (i + 1) / 2))
    //     {
    //         // printf("%d %d\n", i, (i * (i + 1) / 2));
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }
    while ((gaus * (gaus + 1)) / 2 <= n)
        gaus++;

    printf("%llu", gaus - 1);

    return 0;
}