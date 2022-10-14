#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100001

// 펠린드롬이면 0 유사 펠린드롬이면 1 그 외 2 반환
int isPalindrome(char *str, int length)
{
    int psd_left, psd_right, psd_flag = 0;

    for (int i = 0; i < length / 2 + 1; i++)
    {
        // 만약 안 맞으면 그 글자 빼보고 다시 검사하기
        if (str[i] != str[length - i - 1])
        {
            psd_flag = 1;
            psd_left = i;
            psd_right = length - i - 1;
            break;
        }
    }

    if (psd_flag == 0)
        return 0; // 검사 모두 통과하면 펠린드롬
    else
    {
        // 만약 안 맞으면 그 글자 앞 뒤 빼보고 다시 검사하기
        int ex_left_flag = 1, ex_right_flag = 1;

        for (int i = psd_left + 1; i < psd_right; i++)
        {
            if (str[i] != str[psd_right - i - 1])
            {
                ex_left_flag = 0;
                break;
            }
        }

        for (int i = psd_left; i < psd_right - 1; i++)
        {
            if (str[i] != str[psd_right - i - 1])
            {
                ex_right_flag = 0;
                break;
            }
        }

        if (ex_left_flag == 0 && ex_right_flag == 0)
            return 2;
        else
            return 1;
    }
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

        printf("%d\n", isPalindrome(str, length));
    }

    return 0;
}