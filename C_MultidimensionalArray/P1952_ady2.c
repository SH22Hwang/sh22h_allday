#include <stdio.h>

int main(void)
{
    int i, m, n, x = 0, y = 0, count = 0, state = 0;

    scanf("%d %d", &m, &n);
    int temp = m * n;
    y--;
    for (i = 0; i < temp; i++)
    {
        if (state == 0)
        {
            x += 1;
            if (x == n)
            {
                n--;
                count++;
                state = 1;
                x = 0;
            }
        }
        if (state == 1)
        {
            y += 1;
            if (y == m)
            {
                m--;
                count++;
                state = 0;
                y = 0;
            }
        }
    }
    printf("%d", count);
}