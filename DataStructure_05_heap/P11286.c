// 절댓값 힙...
// 최소힙에서 변형
// data(절댓값)와 bit(1 / -1)를 따로 저장
// 출력할때는 data와 bit 곱해서 반환

#include <stdio.h>
#define MAX_NUM 100001

typedef struct _node
{
    int data; // 절댓값
    int bit;  // bit
} node;

node heap[MAX_NUM]; // 구조체 배열
node temp_node;
int size = 1, target, next;

int pop()
{
    if (size == 1)
        return 0;

    else
    {
        node res = heap[1];     // 가장 작은 값 반환
        heap[1] = heap[--size]; // 마지막 노드 값 루트 노드로

        for (target = 1; target * 2 < size;)
        {
            if (size > target * 2 + 1)
            {
                if (heap[target * 2].data == heap[target * 2 + 1].data)                                   // 절댓값 같을 때
                    next = heap[target * 2].bit < heap[target * 2 + 1].bit ? target * 2 : target * 2 + 1; // 음수 선택
                else if (heap[target * 2].data < heap[target * 2 + 1].data)                               // next: 더 작은 데이터
                    next = target * 2;
                else
                    next = target * 2 + 1;
            }
            else
                next = target * 2; // 자식노드 1개 뿐일 때

            if (heap[target].data > heap[next].data) // 부모노드의 data가 자식노드의 data보다 크면 swap
            {
                temp_node = heap[target];
                heap[target] = heap[next];
                heap[next] = temp_node;

                target = next;
            }
            else if (heap[target].data == heap[next].data) // 부모노드의 data가 자식노드의 data와 같으면
            {
                if (heap[target].bit > heap[next].bit) // 자식이 작으면 swap 아니면 continue
                                                       // 실수: target / 2 → next
                {
                    temp_node = heap[target];
                    heap[target] = heap[next];
                    heap[next] = temp_node;
                }

                target = next;
            }
            else
                break;
        }

        // 절댓값 힙 만족하게 정리 후 data bit 곱해서 값 반환
        return res.data * res.bit;
    }
}

void push(int input)
{
    node newnode;
    if (input > 0)
    {
        newnode.data = input;
        newnode.bit = 1;
    }
    else
    {
        newnode.data = -input;
        newnode.bit = -1;
    }

    heap[size++] = newnode;
    for (target = size - 1; heap[target].data <= heap[target / 2].data; target /= 2)
    {
        if (heap[target].data == heap[target / 2].data) // 절댓값 같을 때
        {
            if (heap[target].bit > heap[target / 2].bit) // 자식이 작으면 swap 아니면 continue
                continue;
        }

        temp_node = heap[target];
        heap[target] = heap[target / 2];
        heap[target / 2] = temp_node;
    }
}
int main()
{
    int num_cases, input;
    scanf("%d", &num_cases);

    while (num_cases--)
    {
        scanf("%d", &input);

        if (input == 0)
            printf("출력: %d\n", pop());
        else
            push(input);
    }
    return 0;
}