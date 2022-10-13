#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);

    while (num--)
    {
        char str[1001], word[20];
        scanf(" %[^\n]s", str);

        int length = strlen(str);

        int j = 0;
        for (int i = 0; i < length; i++)
        {
            j = 0;
            while (str[i] != ' ')
            {
                if (i >= length)
                    break;
                word[j++] = str[i++];
            }

            while (j--)
                printf("%c", word[j]);

            printf(" ");
        }

        printf("\n");
    }

    return 0;
}