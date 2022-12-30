/**
 * @file P1966.c
 * @date 2022-12-16
 *
 * 프린터 큐
 * 정렬하고 큐에 넣은 다음 팝해야 할 듯.
 *
 */

#include <stdio.h>

#define MAX_SIZE 101

typedef struct _node
{
    int idx;
    int priority;
} node;

node queue[MAX_SIZE];
int idx_rear = 0, idx_front = 0;

void push(node p);
int pop();
int next_pos(int idx);
int is_empty();

int main()
{
    int tc, num_paper, target;

    scanf("%d", &tc);

    while (tc--)
    {
        scanf("%d %d", num_paper, target);

        for (int i = 0; i < num_paper; i++)
        {
            node newnode;
            newnode.idx = i;
            scanf("%d", &newnode.priority);

            push(newnode);
        }
    }

    return 0;
}

void push(node x)
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

int next_pos(int idx)
{
    return idx == MAX_SIZE ? 1 : idx + 1;
}

int is_empty()
{
    return idx_rear == idx_front ? 1 : 0;
}
