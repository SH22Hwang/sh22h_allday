#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000005

char stack[MAX_SIZE];
int idx_top = -1;

int is_empty()
{
    return idx_top < 0 ? 1 : 0;
}

int is_full()
{
    return idx_top < MAX_SIZE - 1 ? 0 : 1;
}

void push(char x)
{
    if (!is_full())
        stack[++idx_top] = x;
}

char pop()
{
    return is_empty() ? -1 : stack[idx_top--];
}

int size()
{
    return idx_top + 1;
}

char top()
{
    return is_empty() ? -1 : stack[idx_top];
}

void print_stack()
{
    if (is_empty())
        printf("FRULA");
    else
    {
        push('\0');
        printf("%s", stack);
    }
}

int main()
{
    char c4[37], str[MAX_SIZE];
    scanf("%s %s", str, c4); // 문자열을 stack처럼 사용

    int len_s = strlen(str);
    int len_c = strlen(c4);

    for (int i = 0; i < len_s; i++)
    {
        push(str[i]);

        if (top() == c4[len_c - 1] && size() >= len_c) // 폭탄보다 길이가 길때만 검사
        {
            for (int j = len_c - 1; j >= 0; j--)
            {
                if (pop() != c4[j])
                {
                    idx_top += len_c - j; // 폭탄 아니면 복원...?
                    break;
                }
            }
        }
    }

    print_stack();

    return 0;
}