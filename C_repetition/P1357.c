// 문자열, 배열을 사용하지 않고, 반복문, 조건문만 사용해서 풀 것.

#include <stdio.h>

int main()
{
    int num1, num2, res;
    int r1 = 0, r2 = 0, r3 = 0;
    scanf("%d %d", &num1, &num2);

    for (int i = 1000; i > 0; i /= 10) // 1000부터 1까지 반복
    {
        if (num1 / i != 0) // 나누었을 때 0이 되면(자리수 보다 i가 크면) 실행 안 함.
        {
            r1 += (num1 % 10) * i; // 원래 수로 복원하여 r1에 저장
            num1 /= 10;            // 그 다음 자리수 구하기
        }

        if (num2 / i != 0)
        {
            r2 += (num2 % 10) * i;
            num2 /= 10;
        }
    }

    res = r1 + r2;
    for (int i = 1000; i > 0; i /= 10) // 결과도 같은 방식으로 출력
    {
        if (res / i != 0)
        {
            r3 += (res % 10) * i;
            res /= 10;
        }
    }

    printf("%d", r3);
    return 0;
}