#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num1, num2, num3, sum;
    int digit[10] = {
        0,
    };
    char int_to_str[20];

    scanf("%d %d %d", &num1, &num2, &num3);
    sum = num1 * num2 * num3;

    // // C 표준 라이브러리
    // sprintf(int_to_str, "%d", sum);
    // int length = strlen(int_to_str);
    // int idx;
    // for (int i = 0; i < length; i++)
    // {
    //     idx = int_to_str[i] - '0';
    //     digit[idx]++;
    // }

    // 반복문으로 계산하기
    while (sum)
    {
        digit[sum % 10]++;
        sum /= 10;
    }

    // 출력
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", digit[i]);
    }

    return 0;
}