#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100001

int isPalindrome(char *str, int length)
{
    for (int i = 0; i < length / 2 + 1; i++)
    {
        if (str[i] != str[length - i - 1])
            return 1;
    }

    return 0;
}

int main()
{
    int num;
    scanf("%d", &num);

    while (num--)
    {
        char str[MAX_SIZE];
        scanf("%s", str);
        int length = strlen(str);

        // 0: 펠린드롬 1: 일단 아님
        int pal_flag = isPalindrome(str, length);

        if (pal_flag)
        {
            // 0: 유사 펠린드롬 1: 일반 문자열
            int pseudo_flag = 0, idx_str;
            char pseudo_str[MAX_SIZE];
            for (int i = 0; i < length; i++)
            {
                idx_str = 0; // 1글자를 제외한 pseudo_str 만들기 O(n)
                for (int j = 0; j < length; j++)
                    if (i != j)
                        pseudo_str[idx_str++] = str[j];

                pseudo_flag = isPalindrome(pseudo_str, length - 1);

                if (!pseudo_flag)
                    break;
            }

            pal_flag += pseudo_flag;
        }

        printf("%d\n", pal_flag);
    }

    return 0;
}