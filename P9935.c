#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000005

int stack[MAX_SIZE];
int idx_top = -1;

int is_empty()
{
    return idx_top < 0 ? 1 : 0;
}

int is_full()
{
    return idx_top < MAX_SIZE - 1 ? 0 : 1;
}

void push(int x)
{
    if (!is_full())
        stack[++idx_top] = x;
}

int pop()
{
    if (is_empty())
        return -1;
    else
        return stack[idx_top--];

    // return is_empty() ? -1 : stack[idx_top--];
}

int size()
{
    return idx_top + 1;
}

int top()
{
    if (is_empty())
        return -1;
    else
        return stack[idx_top];
    // return is_empty() ? -1 : stack[idx_top--];
}

int main()
{
    char str[MAX_SIZE];
    char c4[37];
    scanf("%s", str); // 문자열을 stack처럼 사용
    scanf("%s", c4);

    int len_s = strlen(stack);
    int len_c = strlen(c4);

    int c = 0;
    for (int i = 0; i < len_s; i++)
    {
        if (str[i] == c4[c])
        {
            push(str[i]);
            for (c = 1; c < len_c; c++)
            {
                if (str[++i] == str[c])
                {
                                }
            }
        }

        printf("%c", str[i])
    }
}
return 0;
}