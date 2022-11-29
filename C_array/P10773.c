#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

int N;

int stack[MAX_SIZE];
int idx_top = -1;

// int is_empty()
// {
//     return idx_top < 0 ? 1 : 0;
// }

int is_full()
{
    return idx_top < MAX_SIZE - 1 ? 0 : 1;
}

void push(int x)
{
    if (!is_full())
        stack[++idx_top] = x;
}

void del(int x)
{
    stack[idx_top--] = x;
}

int sum()
{
    int result = 0;

    for (int i = 0; i < idx_top + 1; i++)
        result += stack[i];

    return result;
}

int main()
{
    scanf("%d", &N);

    while (N--)
    {
        int cmd;
        scanf(" %d", &cmd);

        if (cmd)
            // pop(cmd);
            push(cmd);
        else
            del(cmd);
    }

    printf("%d", sum());
    return 0;
}