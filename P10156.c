#include <stdio.h>

int K, N, M;

int main()
{
    scanf("%d %d %d", &K, &N, &M);

    int temp = K * N - M;
    printf("%d", temp < 0 ? 0 : temp);

    return 0;
}