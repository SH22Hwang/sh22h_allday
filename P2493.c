#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 500005

typedef struct _tower
{
    int height;
    int index;
} tower;

tower tower_stack[MAX_SIZE];
int idx_top = -1;

int is_empty()
{
    return idx_top < 0 ? 1 : 0;
}

int is_full()
{
    return idx_top < MAX_SIZE - 1 ? 0 : 1;
}

void push(int x, int idx)
{
    if (!is_full())
    {
        ++idx_top;
        tower_stack[idx_top].height = x;
        tower_stack[idx_top].index = idx;
    }
}

tower pop()
{
    // return is_empty() ? 0 : tower_stack[idx_top--];
    return tower_stack[idx_top--];
}

tower top()
{
    // return is_empty() ? 0 : tower_stack[idx_top];
    return tower_stack[idx_top];
}

int main()
{
    int N, high = 0;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        int input;
        scanf("%d", &input);

        if (input > high)
        {
            high = input;
            push(input, i);
            printf("0 ");
        }
        else
        {
            while (1)
            {
                if (input > top().height)
                {
                    pop();
                    continue;
                }
                else
                {
                    printf("%d ", top().index);
                    push(input, i);
                    break;
                }
            }
        }
    }

    return 0;
}