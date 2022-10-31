#include <stdio.h>

int heap[100001], size = 1, i, input, TC, target, next;

int pop()
{
    if (size == 1)
        return 0;

    else
    {
        int res = heap[1];
        heap[1] = heap[--size];
        for (target = 1; target * 2 < size;)
        {
            if (size > target * 2 + 1)
                next = heap[target * 2] < heap[target * 2 + 1] ? target * 2 : target * 2 + 1;
            else
                next = target * 2;

            if (heap[target] > heap[next])
            {
                input = heap[target];
                heap[target] = heap[next];
                heap[next] = input;
                target = next;
            }
            else
                break;
        }
        return res;
    }
}

void push(int data)
{
    heap[size++] = data;
    for (target = size - 1; heap[target] < heap[target / 2]; target /= 2)
    {
        int temp;
        temp = heap[target];
        heap[target] = heap[target / 2];
        heap[target / 2] = temp;
    }
}
int main()
{
    scanf("%d", &TC);
    for (i = 0; i < TC; i++)
    {
        scanf("%d", &input);

        if (input == 0)
            printf("%d\n", pop());
        else
            push(input);
    }
    return 0;
}