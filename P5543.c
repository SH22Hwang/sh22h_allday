#include <stdio.h>

int main()
{
    int sd, jd, hd, cola, cider;

    scanf("%d", &sd);
    scanf("%d", &jd);
    scanf("%d", &hd);
    scanf("%d", &cola);
    scanf("%d", &cider);

    int burger = sd;

    if (burger > jd)
        burger = jd;
    if (burger > hd)
        burger = hd;

    printf("%d", cola < cider ? burger + cola - 50 : burger + cider - 50);
    return 0;
}