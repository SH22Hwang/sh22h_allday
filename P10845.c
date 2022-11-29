#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10005

int N;

int queue[MAX_SIZE];
int idx_rear = 0, idx_front = 0;

int next_pos(int idx)
{
    return idx == MAX_SIZE ? 1 : idx + 1;
}

int is_empty()
{
    return idx_rear == idx_front ? 1 : 0;
}

void push(int x)
{
    idx_rear = next_pos(idx_rear);
    queue[idx_rear] = x;
}

int pop()
{
    if (is_empty())
        return -1;
    else
    {
        idx_front = next_pos(idx_front);
        return queue[idx_front];
    }

    // return is_empty() ? -1 : stack[idx_top--];
}

int size()
{
    int s = next_pos(idx_rear) - next_pos(idx_front);

    return s < 0 ? -s : s;
}

int front()
{
    return is_empty() ? -1 : queue[next_pos(idx_front)];
}

int back()
{
    return is_empty() ? -1 : queue[idx_rear];
}

int main()
{
    scanf("%d", &N);

    while (N--)
    {
        char cmd1[10];
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
        else if (!strcmp(cmd1, "front"))
        {
            printf("%d\n", front());
        }
        else if (!strcmp(cmd1, "back"))
        {
            printf("%d\n", back());
        }
    }
    return 0;
}
