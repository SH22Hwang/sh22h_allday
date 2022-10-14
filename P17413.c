#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100001

int main()
{
    char str[MAX_SIZE], word[20];
    scanf(" %[^\n]s", str);

    int length = strlen(str);

    int idx_word, tag = 0;
    for (int i = 0; i < length; i++)
    {
        // tag가 열리면 tag = 1 닫힐때까지 유지
        if (str[i] == '<')
            tag = 1;
        else if (str[i] == '>')
        {
            tag = 0;
            printf("%c", str[i]);
            continue;
        }

        if (tag)
        {
            printf("%c", str[i]);
        }
        else
        {
            idx_word = 0;
            // 단어 뒤집기 준비
            while (1)
            {
                if (i >= length || str[i] == ' ' || str[i] == '<')
                    break;
                word[idx_word++] = str[i++];
            }

            // 뒤집한 단어 출력
            while (idx_word--)
                printf("%c", word[idx_word]);

            // 띄어쓰기면 출력 < 이면 1 감소 후 tag 조건문 실행
            if (str[i] == ' ')
                printf(" ");
            else if (str[i] == '<')
                i--;
        }
    }

    return 0;
}