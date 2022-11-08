#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    while (1)
    {
        int num;
        scanf("%d", &num);
        if (num == 0)
            break;

        char first[21] = {
            'z',
        };
        while (num--)
        {
            char str[21];
            scanf("%s", &str);

            int len = strlen(str);
            for (int j = 0; j < len; j++)
            {
                if (str[j] <= 90 && str[j] >= 65)
                    str[j] += 32;
            }

            int result = strcmp(str, first);
            if (result > 0)
        }
    }

    return 0;
}