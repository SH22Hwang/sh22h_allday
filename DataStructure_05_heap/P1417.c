#include <stdio.h>
#define MAX_NUM 101

int max_heap[MAX_NUM] = {
    2147483647, // int 최대값
    0,
};
int max_size = 1, target, next, temp_node;

void push(int data);
void max_check();

int main()
{
    int tc, dasom, input, bribe = 0;
    scanf("%d", &tc);
    scanf("%d", &dasom);

    tc--;
    while (tc--)
    {
        scanf("%d", &input);
        push(input);
    }

    while (max_heap[1] >= dasom)
    {
        max_heap[1]--;
        dasom++;
        bribe++;
        max_check();
    }

    printf("%d", bribe);

    return 0;
}

void push(int data)
{
    max_heap[max_size++] = data;
    for (target = max_size - 1; max_heap[target] > max_heap[target / 2]; target /= 2)
    {
        temp_node = max_heap[target];
        max_heap[target] = max_heap[target / 2];
        max_heap[target / 2] = temp_node;
    }
}

void max_check()
{
    // 최대 힙 만족하게 정리
    for (target = 1; target * 2 < max_size;)
    {
        if (max_size > target * 2 + 1)
            // 자식노드 2개 중 큰 값 선택
            next = max_heap[target * 2] > max_heap[target * 2 + 1] ? target * 2 : target * 2 + 1;
        else
            next = target * 2; // 자식노드 1개 뿐일 때

        if (max_heap[target] < max_heap[next]) // 부모노드가 자식노드보다 작으면 swap
        {
            temp_node = max_heap[target];
            max_heap[target] = max_heap[next];
            max_heap[next] = temp_node;
            target = next;
        }
        else
            break;
    }
}