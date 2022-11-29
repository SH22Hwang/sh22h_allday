#include <stdio.h>
#include <string.h>

int main()
{
    char num1[10001], num2[10001];
    int result[10003];
    scanf("%s %s", num1, num2);

    int len_num1 = strlen(num1);
    int len_num2 = strlen(num2);

    int temp, count = 0, carry = 0;
    while (len_num1 > 0 || len_num2 > 0)
    {
        temp = 0;
        if (len_num1 > 0)
            temp += num1[--len_num1] - '0';
        if (len_num2 > 0)
            temp += num2[--len_num2] - '0';

        if (temp + carry < 10)
        {
            result[count++] = temp + carry;
            carry = 0;
        }
        else
        {
            result[count++] = temp - 10 + carry;
            carry = 1;
        }
    }

    if (carry)
        printf("%d", carry);

    for (int i = count - 1; i >= 0; i--)
        printf("%d", result[i]);

    return 0;
}