#include <stdio.h>
#include <stdlib.h>

int main()
{
    int result, num;
    scanf("%d", &num);

    result += num;

    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &num);
        if (abs(100 - result) >= abs(100 - (num + result)))
            result += num;
        else
            break;
    }

    printf("%d", result);
    return 0;
}