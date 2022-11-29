#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100009

char arr[MAX_SIZE][52];
char sort[MAX_SIZE][52];

void merge_sort(int left, int right);
void merge2arr(int left, int mid, int right);

int main(void)
{

    int num, idx = 1, flag = 0;
    scanf("%d", &num);

    scanf("%s", arr[0]);
    for (int i = 1; i < num; i++)
    {
        char temp[52];
        scanf("%s", temp);

        for (int j = 0; j < i; j++)
        {
            if (strcmp(temp, arr[j]) == 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag)
        {
            flag = 0;
            continue;
        }
        else
        {
            strcpy(arr[idx], temp);
            idx++;
        }
    }

    merge_sort(0, idx - 1);

    if (idx == 1)
    {
        printf("%s\n", arr[0]);
    }
    else
    {
        for (int j = 0; j < idx; j++)
            printf("%s\n", sort[j]);
    }
    return 0;
}

void merge_sort(int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge2arr(left, mid, right);
    }
}

void merge2arr(int left, int mid, int right)
{
    int fidx = left;
    int ridx = mid + 1;
    int sidx = left;

    while (fidx <= mid && ridx <= right)
    {
        int flen = strlen(arr[fidx]);
        int rlen = strlen(arr[ridx]);

        if (flen < rlen)
            strcpy(sort[sidx++], arr[fidx++]);
        else if (flen > rlen)
            strcpy(sort[sidx++], arr[ridx++]);
        else
        {
            if (strcmp(arr[fidx], arr[ridx]) < 0) // strcmp를 쓸 때는 == -1 대신 < 0 을 쓰자
                strcpy(sort[sidx++], arr[fidx++]);
            else
                strcpy(sort[sidx++], arr[ridx++]);
        }
    }

    if (ridx > right)
    {
        for (int i = fidx; i <= mid; i++)
            strcpy(sort[sidx++], arr[i]);
    }
    else
    {
        for (int i = ridx; i <= right; i++)
            strcpy(sort[sidx++], arr[i]);
    }

    for (int j = left; j <= right; j++)
        strcpy(arr[j], sort[j]);
}
