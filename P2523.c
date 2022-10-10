#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N, P, num, first = 0, last = 0;
    scanf("%d %d", &N, &P);

    int *arr = (int *)calloc(P + 1, sizeof(int));

    num = N * N % P;
    arr[0] = num;
    for (int i = 1;; i++)
    {
        if (num == 0)
        {
            first = 1;
            last = 0;
            break;
        }

        num = num * N % P;

        // 배열에 있는지 검사하기
        for (int j = 0; j < i; j++)
        {
            if (num == arr[j])
            {
                last = j;
                break;
            }
        }

        if (last)
        {
            first = i;
            break;
        }
        else
        {
            arr[i] = num;
        }
    }

    printf("%d", first - last);
    return 0;
}