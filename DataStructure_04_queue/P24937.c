#include <stdio.h>
#include <string.h>

#define MAX_SIZE 20

char queue[MAX_SIZE] = "SciComLove";
int idx_rear = 9, idx_front = -1;

int next_pos(int idx);
int is_empty();
void push(char x);
char pop();

int main()
{
    int tc;
    scanf("%d", &tc);

    tc %= 10; // 10의 나머지만큼만 반복할 것.

    while (tc--)
    {
        push(pop());
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%c", pop());
    }

    return 0;
}

int next_pos(int idx)
{
    return idx == MAX_SIZE ? 1 : idx + 1;
}

int is_empty()
{
    return idx_rear == idx_front ? 1 : 0;
}

void push(char x)
{
    idx_rear = next_pos(idx_rear);
    queue[idx_rear] = x;
}

char pop()
{
    if (is_empty())
        return 0;
    else
    {
        idx_front = next_pos(idx_front);
        return queue[idx_front];
    }
}