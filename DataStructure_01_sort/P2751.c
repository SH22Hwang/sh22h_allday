#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000009

int sort[MAX_SIZE];

void merge_sort(int *arr, int left, int right);
void merge2arr(int *arr, int left, int mid, int right);

int main(void)
{
    int num;
    scanf("%d", &num);
    if (num == 1)
    {
        scanf("%d", &num);
        printf("%d", num);
        return 0;
    }

    int *arr = (int *)malloc(sizeof(int) * num);
    for (int i = 0; i < num; i++)
        scanf("%d", &arr[i]);

    merge_sort(arr, 0, num - 1);

    for (int j = 0; j < num; j++)
        printf("%d ", sort[j]);

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
