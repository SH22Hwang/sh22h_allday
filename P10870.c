// 어떻게 풀어야할지 몰라서 DP로 품

#include <stdio.h>

int main()
{
    int arr[21];
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= 20; i++)
        arr[i] = arr[i - 1] + arr[i - 2];

    int num;
    scanf("%d", &num);

    printf("%d", arr[num]);

    return 0;
}