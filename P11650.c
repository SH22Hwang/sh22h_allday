#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100009

typedef struct _node // 좌표 저장하는 구조체
{
    int x;
    int y;
} node;

node arr[MAX_SIZE];
node sort[MAX_SIZE];

void merge_sort(node *arr, int left, int right);
void merge2arr(node *arr, int left, int mid, int right);

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

    for (int i = 0; i < num; i++)
    {
        node newnode;
        scanf("%d %d", &newnode.x, &newnode.y);
        arr[i] = newnode;
    }

    merge_sort(arr, 0, num - 1);

    for (int j = 0; j < num; j++)
        printf("%d %d\n", sort[j].x, sort[j].y);

    return 0;
}

void merge_sort(node *arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge2arr(arr, left, mid, right);
    }
}

void merge2arr(node *arr, int left, int mid, int right)
{
    int fidx = left;
    int ridx = mid + 1;
    int sidx = left;

    while (fidx <= mid && ridx <= right)
    {
        if (arr[fidx].x < arr[ridx].x)
            sort[sidx++] = arr[fidx++];
        else if (arr[fidx].x > arr[ridx].x)
            sort[sidx++] = arr[ridx++];
        else // x 좌표 같은 경우
        {
            if (arr[fidx].y < arr[ridx].y)
                sort[sidx++] = arr[fidx++];
            else
                sort[sidx++] = arr[ridx++];
        }
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
