#include <stdio.h>

int main()
{
    int cards[101] = {};

    int i, N, M;
    scanf("%d %d", &N, &M);

    for (i = 0; i < N; i++)
        scanf(" %d", &cards[i]);

    int result = 0;
    for (int c1 = 0; c1 < N - 2; c1++)
    {
        for (int c2 = c1 + 1; c2 < N - 1; c2++)
        {
            for (int c3 = c2 + 1; c3 < N; c3++)
            {
                int temp = cards[c1] + cards[c2] + cards[c3];
                if (temp <= M && temp > result)
                    result = temp;
            }
        }
    }

    printf("%d", result);
    return 0;
}