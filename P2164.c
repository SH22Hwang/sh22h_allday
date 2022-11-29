#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 105

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
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        push(i);

    while (size() != 1)
    {
        pop();
        push(pop());
    }

    printf("%d", front());

    return 0;
}
