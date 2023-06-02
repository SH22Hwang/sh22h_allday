// 정수 N을 m으로 나눈 나머지가 R이 되도록 하는 모든 양의 정수 m의 합을 구하라.
// 약수 구하고 약수 + r만큼의 수?

#include <stdio.h>
#include <math.h>
#define MAX_SIZE 1000

int main()
{
    int nums[MAX_SIZE] = {0}; // 약수 찾기
    int n, r;
    scanf("%d %d", &n, &r);

    int sq = (int)sqrt(n);
    for (int i = 2; i <= sq; i++)
    {
        if (n % i == 0)
            printf("%d %d ", i, n / i);
    }

    return 0;
}