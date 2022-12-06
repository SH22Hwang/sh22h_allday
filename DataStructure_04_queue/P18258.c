#include <stdio.h>
#include <string.h>

#define MAX_SIZE 29

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
    int tc;
    scanf("%d", &tc);

    while (tc--)
    {
        char cmd[9];
        scanf("%s", cmd);

        if (!strcmp(cmd, "push"))
        {
            int num;
            scanf("%d", &num);

            push(num);
            continue;
        }

        if (!strcmp(cmd, "pop"))
        {
            printf("%d\n", pop());
            continue;
        }

        if (!strcmp(cmd, "size"))
        {
            printf("%d\n", size());
            continue;
        }

        if (!strcmp(cmd, "empty"))
        {
            printf("%d\n", is_empty());
            continue;
        }

        if (!strcmp(cmd, "front"))
        {
            printf("%d\n", front());
            continue;
        }

        if (!strcmp(cmd, "back"))
        {
            printf("%d\n", back());
            continue;
        }
    }

    return 0;
}
