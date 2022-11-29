#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

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
    return is_empty() ? -1 : stack[idx_top--];
}

int size()
{
    return idx_top + 1;
}

int top()
{
    return is_empty() ? -1 : stack[idx_top--];
}

int main()
{
    int N;
    scanf("%d", &N);

    while (N--)
    {
        char cmd1[6];
        scanf(" %s", cmd1);

        if (!strcmp(cmd1, "push")) // Return Value from strcmp() if strings are equal return 0
        {
            int num;
            scanf(" %d", &num);

            push(num);
        }
        else if (!strcmp(cmd1, "pop"))
        {
            printf("%d\n", pop());
        }
        else if (!strcmp(cmd1, "size"))
        {
            printf("%d\n", size());
        }
        else if (!strcmp(cmd1, "empty"))
        {
            printf("%d\n", is_empty());
        }
        else if (!strcmp(cmd1, "top"))
        {
            printf("%d\n", top());
        }
    }
    return 0;
}