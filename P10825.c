#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100009

typedef struct _node // 좌표 저장하는 구조체
{
    char name[20];
    int kor;
    int eng;
    int math;
} node;

node arr[MAX_SIZE];
node sort[MAX_SIZE];

void merge_sort(node *arr, int left, int right);
void merge2arr(node *arr, int left, int mid, int right);

int main(void)
{
    int num;
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        node newnode;
        scanf("%s %d %d %d", &newnode.name, &newnode.kor, &newnode.eng, &newnode.math);

        if (num == 1)
        {
            printf("%s\n", newnode.name);
            return 0;
        }
        arr[i] = newnode;
    }

    node last;
    last.kor = 0;
    last.eng = 0;
    last.math = 0;
    arr[num] = last;

    merge_sort(arr, 0, num - 1);

    for (int j = 0; j < num; j++)
        printf("%s\n", sort[j].name);

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
        if (arr[fidx].kor > arr[ridx].kor) // 국어 내림차순
            sort[sidx++] = arr[fidx++];
        else if (arr[fidx].kor < arr[ridx].kor)
            sort[sidx++] = arr[ridx++];
        else // 국어 점수 같은 경우
        {
            if (arr[fidx].eng < arr[ridx].eng) // 영어 오름차순
                sort[sidx++] = arr[fidx++];
            else if (arr[fidx].eng > arr[ridx].eng)
                sort[sidx++] = arr[ridx++];
            else // 영어점수 같은 경우
            {
                if (arr[fidx].math > arr[ridx].math) // 수학 내림차순
                    sort[sidx++] = arr[fidx++];
                else if (arr[fidx].math < arr[ridx].math)
                    sort[sidx++] = arr[ridx++];
                else // 모든 점수 같은 경우
                {
                    if (strcmp(arr[fidx].name, arr[ridx].name) < 0) // 아스키코드순
                                                                    // strcmp를 쓸 때는 == -1 대신 < 0 을 쓰자
                        sort[sidx++] = arr[fidx++];
                    else
                        sort[sidx++] = arr[ridx++];
                }
            }
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
