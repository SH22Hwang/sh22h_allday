#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000000

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
    // if (is_empty())
    //     return 0;
    // else
    //     return stack[idx_top--];

    return is_empty() ? 0 : stack[idx_top--];
}

void clear()
{
    stack[0] = '\0';
    idx_top = -1;
}

int top()
{
    // if (is_empty())
    //     return -1;
    // else
    //     return stack[idx_top];
    return is_empty() ? -1 : stack[idx_top];
}

int main()
{
    scanf("%d", &N);

    int tower[N];
    int result[N] = {
        0,
    };

    for (int i = 0; i < N, i++)
    {
        scanf(" %d", tower[i]);
    }

    for (int i = 0; i < N; i++)
    {
        if (tower[i] > top())
        {
            result[i] = 0
        }
        else
        {
            for (int j = i; j < N;)
        }
    }

    return 0;
}