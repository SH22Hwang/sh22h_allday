#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 51

int sort[MAX_SIZE];

void merge_sort(int *arr, int left, int right);
void merge2arr(int *arr, int left, int mid, int right);

int main(void)
{
    int num;
    scanf("%d", &num);

    int *arrA = (int *)malloc(sizeof(int) * num);
    for (int i = 0; i < num; i++)
        scanf("%d", &arrA[i]);

    merge_sort(arrA, 0, num - 1);

    int *arrB = (int *)malloc(sizeof(int) * num);
    for (int i = 0; i < num; i++)
        scanf("%d", &arrB[i]);

    int max, res = 0;
    for (int i = 0; i < num; i++)
    {
        max = 0;
        for (int j = 0; j < num; j++)
        {
            if (arrB[max] < arrB[j])
                max = j;
        }

        res += arrA[i] * arrB[max];
        arrA[i] = -101;
        arrB[max] = -101;
    }

    printf("%d", res);
    return 0;
}

void merge_sort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge2arr(arr, left, mid, right);
    }
}

void merge2arr(int *arr, int left, int mid, int right)
{
    int fidx = left;
    int ridx = mid + 1;
    int sidx = left;

    while (fidx <= mid && ridx <= right)
    {
        if (arr[fidx] < arr[ridx])
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