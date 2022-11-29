#include <stdio.h>

int main()
{
    int num, result = 99, temp;
    int digits[4];
    scanf("%d", &num);

    if (num < 100)
        result = num;
    else if (num < 111)
        result = 99;
    else
    {
        if (num > 999)
            num = 999;
        for (int i = 111; i <= num; i++)
        {
            temp = i;
            for (int j = 0; temp > 0; j++)
            {
                digits[j] = temp % 10;
                temp /= 10;
            }
            if (digits[0] - digits[1] == digits[1] - digits[2])
                result++;
        }
    }

    printf("%d", result);
    return 0;
}