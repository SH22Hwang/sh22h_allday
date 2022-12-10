/**
 * @file P1655.c
 * @author 황승현 (ghkd3531@gnu.ac.kr)
 * @brief 가운데를 말해요.. 중간값 알고리즘 구현하기
 * @version 0.1
 * @date 2022-12-06
 *
 * @copyright Copyright (c) 2022
 *
 * 중간값 알고리즘:
 * 1. 최대힙 최소힙 번갈아가면서 push
 * 2. 조건 확인
 * 2-1. 최대힙의 root값이 최소힙의root값보다 항상 작아야한다.
 * 2-2. 조건을 만족하지 않으면 최대힙과 최소힙의 root값이 swap
 * 2-3. swap후 힙 조건에 따라 정렬
 * 3. 최대힙의 root값이 항상 중간값
 */

#include <stdio.h>
#define MAX_NUM 100001

int min_heap[MAX_NUM] = {
    -2147483646, // int 최대값
    0,
};
int max_heap[MAX_NUM] = {
    2147483647, // int 최대값
    0,
};

int min_size = 1, max_size = 1;
int next, target, temp_node;

void min_push(int data);
void max_push(int data);
void check_swap();
void min_check();
void max_check();

int main()
{
    int tc, input, flag = 1;
    scanf("%d", &tc);

    for (int i = 0; i < tc; i++)
    {
        scanf("%d", &input);

        if (flag)
        {
            max_push(input);
            flag = 0;
        }
        else
        {
            min_push(input);
            flag = 1;
        }

        if (i != 0)
            check_swap();

        printf("%d\n", max_heap[1]);
    }
    return 0;
}

void min_push(int data)
{
    min_heap[min_size++] = data;
    for (target = min_size - 1; min_heap[target] < min_heap[target / 2]; target /= 2)
    {
        temp_node = min_heap[target];
        min_heap[target] = min_heap[target / 2];
        min_heap[target / 2] = temp_node;
    }
}

void max_push(int data)
{
    max_heap[max_size++] = data;
    for (target = max_size - 1; max_heap[target] > max_heap[target / 2]; target /= 2)
    {
        temp_node = max_heap[target];
        max_heap[target] = max_heap[target / 2];
        max_heap[target / 2] = temp_node;
    }
}

void check_swap()
{
    if (max_heap[1] < min_heap[1])
        return;
    else
    {
        temp_node = max_heap[1];
        max_heap[1] = min_heap[1];
        min_heap[1] = temp_node;

        max_check();
        min_check();
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

void min_check()
{
    // 최소 힙 만족하게 정리
    for (target = 1; target * 2 < min_size;)
    {
        if (min_size > target * 2 + 1)
            // 자식노드 2개 중 작은 값 선택
            next = min_heap[target * 2] < min_heap[target * 2 + 1] ? target * 2 : target * 2 + 1;
        else
            next = target * 2; // 자식노드 1개 뿐일 때

        if (min_heap[target] > min_heap[next]) // 부모노드가 자식노드보다 크면 swap
        {
            temp_node = min_heap[target];
            min_heap[target] = min_heap[next];
            min_heap[next] = temp_node;
            target = next;
        }
        else
            break;
    }
}