#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

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

int pop()
{
    if (is_empty())
        return 0;
    else
        return stack[idx_top--];

    // return is_empty() ? -1 : stack[idx_top--];
}

int top()
{
    if (is_empty())
        return 0;
    else
        return stack[idx_top];
    // return is_empty() ? -1 : stack[idx_top--];
}

int size()
{
    return idx_top + 1;
}

int main()
{
    int result = 0;
    char str[MAX_SIZE];
    scanf(" %s", str);

    int length = strlen(str);
    // int bar = 0;
    char temp;

    push(1);
    for (int i = 1; i < length; i++)
    {
        if (str[i] == '(')
            push(1); // stack이 비어있으면 0 반환
        else
        {
            pop();
            if (str[i] == str[i - 1])
                result++;
            else
                result += size();
        }
    }

    printf("%d", result);
    return 0;
}
