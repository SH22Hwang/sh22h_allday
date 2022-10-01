// 올데이 배열 문제집

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000 // 상수가 1000000 (백만)일 때 에러 발생

int main()
{
    // int arr[MAX_SIZE]; // 문제는 대부분 배열

    int num, temp;
    int max = -1 * MAX_SIZE;
    int min = MAX_SIZE;

    scanf("%d", &num); // 배열의 길이

    int *arr = (int *)malloc(sizeof(int) * num);
    for (int i = 0; i < num; i++)
    {
        scanf(" %d", &temp);
        arr[i] = temp;
    }

    for (int i = 0; i < num; i++)
    {
        if (arr[i] > max)
            max = arr[i];

        if (arr[i] < min)
            min = arr[i];
    }

    printf("%d %d", min, max);
    return 0;
}