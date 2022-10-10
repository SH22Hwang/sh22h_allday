#include <stdio.h>

void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);

int main()
{
    int arr[9] = {
        0,
    };
    int sum, target;
    int res[2] = {0, 0};

    for (int i = 0; i < 9; i++)
        scanf(" %d", &arr[i]);

    sum = 0;
    for (int i = 0; i < 9; i++)
        sum += arr[i];

    target = sum - 100;

    mergeSort(arr, 0, 8);

    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (target == (arr[i] + arr[j]))
            {
                res[0] = i;
                res[1] = j;
                break;
            }
        }

        if (res[1] > 0)
            break;
    }

    for (int i = 0; i < 9; i++)
    {
        if (i == res[0] || i == res[1])
            continue;
        else
            printf("%d\n", arr[i]);
    }

    return 0;
}

void merge(int arr[], int left, int mid, int right)
{
    int arrCopy[100], i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            arrCopy[k++] = arr[i++];
        else
            arrCopy[k++] = arr[j++];
    }
    while (i <= mid)
        arrCopy[k++] = arr[i++];
    while (j <= right)
        arrCopy[k++] = arr[j++];
    for (int a = left; a <= right; a++)
        arr[a] = arrCopy[a];
}

void mergeSort(int arr[], int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}