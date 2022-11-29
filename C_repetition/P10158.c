#include <stdio.h>

int main()
{
    int w, h, p, q, t;
    scanf("%d %d", &w, &h);
    scanf("%d %d", &p, &q);
    scanf("%d", &t);

    int x = (t + p) % (2 * w);
    int y = (t + q) % (2 * h);

    // if (x > w)
    //     x = 2 * w - x;

    // if (y > h)
    //     y = 2 * h - y;

    // printf("%d %d", x, y);

    printf("%d %d", x > w ? 2 * w - x : x, y > h ? 2 * h - y : y);

    return 0;
}