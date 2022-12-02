#include <stdio.h>
#include <string.h>

int is_ok(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        return 1;
    else
        return 0;
}

int main()
{
    char ary[5][16] = {
        0,
    };

    for (int i = 0; i < 5; i++)
        scanf(" %s", ary[i]);

    for (int col = 0; col < 16; col++)
    {
        for (int row = 0; row < 5; row++)
        {
            if (is_ok(ary[row][col]))
                printf("%c", ary[row][col]);
        }
    }

    return 0;
}