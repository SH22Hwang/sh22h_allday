#include <stdio.h>
#define MAX_NUM 100001

int heap[MAX_NUM], size = 1, target, next, temp_node;

int pop()
{
    if (size == 1)
        return 0;

    else
    {
        int res = heap[1];      // 가장 작은 값 반환
        heap[1] = heap[--size]; // 마지막 노드 값 루트 노드로

        for (target = 1; target * 2 < size;)
        {
            if (size > target * 2 + 1)
                // 자식노드 2개 중 작은 값 선택
                next = heap[target * 2] < heap[target * 2 + 1] ? target * 2 : target * 2 + 1;
            else
                next = target * 2; // 자식노드 1개 뿐일 때

            if (heap[target] > heap[next]) // 부모노드가 자식노드보다 크면 swap
            {
                temp_node = heap[target];
                heap[target] = heap[next];
                heap[next] = temp_node;
                target = next;
            }
            else
                break;
        }
        // 최소 힙 만족하게 정리 후 값 반환
        return res;
    }
}

void push(int data)
{
    heap[size++] = data;
    for (target = size - 1; heap[target] < heap[target / 2]; target /= 2)
    {
        temp_node = heap[target];
        heap[target] = heap[target / 2];
        heap[target / 2] = temp_node;
    }
}
int main()
{
    int num_cases, input, temp = 0, result = 0;
    scanf("%d", &num_cases);

    while (num_cases--)
    {
        scanf("%d", &input);
        push(input);
    }

    while (size != 2)
    {
        temp = pop() + pop();
        push(temp);
        result += temp;
    }

    printf("%d", result);
    return 0;
}