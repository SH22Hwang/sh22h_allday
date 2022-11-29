#include <stdio.h>

int main()
{
    int num = 0;
    scanf("%d", &num);
    int sugar3 = num / 3;

    for (int i = 0; i <= sugar3; i++)
    {
        if (num % 5)
            num -= 3;
        else
        {
            printf("%d", (num / 5 + i));
            break;
        }
    }

    if (num < 5 && num != 0)
        printf("-1");

    return 0;
}