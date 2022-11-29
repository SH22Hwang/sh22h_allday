
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

int N;

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

void clear()
{
    stack[0] = '\n';
    idx_top = -1;
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
    scanf("%d", &N);

    int result = 0;
    while (N--)
    {
        char str[MAX_SIZE];
        scanf(" %s", str);

        int length = strlen(str);
        if (length % 2)
            continue;

        push(str[0]);
        for (int i = 1; i < length; i++)
        {
            if (str[i] == top())
                pop(); // stack이 비어있으면 0 반환
            else
                push(str[i]);
        }

        if (is_empty())
            result++;

        clear();
    }

    printf("%d", result);
    return 0;
}
