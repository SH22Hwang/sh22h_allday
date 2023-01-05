#include <stdio.h>

#define MAX_SIZE 15

char queue[MAX_SIZE];
int idx_front = 0, idx_rear = 0;

int next_pos(int idx);
int is_empty();
void push(int x);
int pop();

int main()
{
    int N, K; // 사람 N명, 제거할 수 K
    scanf("%d %d", &N, &K);

    for (int i = 1; i <= N; i++)
    {
        push(i);
    }

    printf("<");
    while (!is_empty())
    {
        for (int j = 0; j < K - 1; j++)
            push(pop());

        printf(is_empty() ? "%d" : "%d, ", pop());
    }
    printf(">");

    return 0;
}

int next_pos(int idx)
{
    return idx + 1 == MAX_SIZE ? 1 : idx + 1;
}

int is_empty()
{
    return next_pos(idx_rear) == next_pos(idx_front) ? 1 : 0;
}

void push(int x)
{
    idx_rear = next_pos(idx_rear);
    queue[idx_rear] = x;
}

int pop()
{
    if (is_empty())
        return 0;
    else
    {
        idx_front = next_pos(idx_front);
        return queue[idx_front];
    }
}