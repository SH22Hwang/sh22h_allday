#include <stdio.h>
#include <string.h>

int main()
{
    int flag = 1;
    char str[21];
    scanf("%s", str);

    int length = strlen(str);
    for (int i = 0; i < length / 2 + 1; i++)
    {
        if (str[i] != str[length - i - 1])
        {
            flag = 0;
            break;
        }
    }

    printf(flag ? "true" : "false");
    return 0;
}