/**
 * @file P1456.c
 * @author 황승현
 * @brief 내맴대로 푸는 C 문제
 * @version 0.1
 * @date 2023-04-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <math.h>

#define MAX_SIZE 10000001

int main(void)
{
    long long sieve[MAX_SIZE] = {
        1,
        1,
        0,
    }; // 0이면 소수 1이면 소수 아님. 0으로 초기화

    long long m, n;
    scanf("%d %d", &m, &n);

    // 소수 구하기
    long long cnt = 0;
    long long sqrtn = (long long)sqrt(n) + 1;
    for (long long i = 2; i < sqrtn; i++)
    {
        if (!sieve[i])
        {
            for (long long j = i + i; j <= sqrtn; j += i)
                sieve[j] = 1;
        }
    }

    for (long long i = 2; i < sqrtn; i++)
    {
        if (!sieve[i])
        {
            for (long long k = i * i; k <= sqrtn; k *= i)
                cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}