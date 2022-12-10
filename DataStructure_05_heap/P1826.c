/**
 * @file P1826.c
 * @author 황승현
 * @date 2022-12-10
 *
 * 백준 1826번 연료채우기
 * 1. 입력받은 주유소를 거리순으로 정렬한다. (mergesort)
 * 2. 정렬한 주유소를 기름량순으로 정렬한다. (heap)
 * 3. ㅁ?ㄹ
 */

#include <stdio.h>

#define MAX_SIZE 11

typedef struct _oilstation
{
    int dist;
    int fuel;
} oilstation;

oilstation arr[MAX_SIZE];  // 입력
oilstation sort[MAX_SIZE]; // 정렬
int heap[MAX_SIZE] = {
    2147483647, // int 최대값
    0,
}; // fuel 넣는 최대 힙
int size = 1, target, next, temp_node;

void merge_sort(oilstation *arr, int left, int right);
void merge2arr(oilstation *arr, int left, int mid, int right);
void push(int fuel);
int pop();

int main()
{
    int num, L, P;
    int cur = 0, cnt = 0; // 현재 위치, 카운터

    scanf("%d", &num);
    for (int i = 0; i < num; i++)
        scanf(" %d %d", &arr[i].dist, &arr[i].fuel);

    scanf(" %d %d", &L, &P);
    merge_sort(arr, 0, num - 1);

    while (L > P)
    {
        while (arr[cur].dist <= P)
        {
            if (cur == num)
                break;

            push(arr[cur++].fuel);
        }

        if (size == 1)
            break;
        cnt++;
        P += pop();
    }

    printf("%d\n", L > P ? -1 : cnt);

    return 0;
}

void merge_sort(oilstation *arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge2arr(arr, left, mid, right);
    }
}

void merge2arr(oilstation *arr, int left, int mid, int right)
{
    int fidx = left;
    int ridx = mid + 1;
    int sidx = left;

    while (fidx <= mid && ridx <= right) // 거리 순 정렬
    {
        if (arr[fidx].dist < arr[ridx].dist)
            sort[sidx++] = arr[fidx++];
        else
            sort[sidx++] = arr[ridx++];
    }

    if (ridx > right)
    {
        for (int i = fidx; i <= mid; i++)
            sort[sidx++] = arr[i];
    }
    else
    {
        for (int i = ridx; i <= right; i++)
            sort[sidx++] = arr[i];
    }

    for (int j = left; j <= right; j++)
        arr[j] = sort[j];
}

void push(int fuel)
{
    heap[size++] = fuel;
    for (target = size - 1; heap[target] > heap[target / 2]; target /= 2)
    {
        temp_node = heap[target];
        heap[target] = heap[target / 2];
        heap[target / 2] = temp_node;
    }
}

int pop()
{
    if (size == 1)
        return 0;

    else
    {
        int res = heap[1];      // 가장 큰 값 반환
        heap[1] = heap[--size]; // 마지막 노드 값 루트 노드로

        for (target = 1; target * 2 < size;)
        {
            if (size > target * 2 + 1)
                // 자식노드 2개 중 큰 값 선택
                next = heap[target * 2] > heap[target * 2 + 1] ? target * 2 : target * 2 + 1;
            else
                next = target * 2; // 자식노드 1개 뿐일 때

            if (heap[target] < heap[next]) // 부모노드가 자식노드보다 작으면 swap
            {
                temp_node = heap[target];
                heap[target] = heap[next];
                heap[next] = temp_node;
                target = next;
            }
            else
                break;
        }
        // 최대 힙 만족하게 정리 후 값 반환
        return res;
    }
}