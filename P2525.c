#include <stdio.h>
int A, B, time;

int main()
{
    scanf("%d %d", &A, &B);
    scanf(" %d", &time);

    int hour = A, minute;

    if ((B + time) < 60)
    {
        minute = B + time;
    }
    else
    {
        hour += (B + time) / 60;
        minute = (B + time) % 60;
    }

    if (hour >= 24)
        hour -= 24;

    printf("%d %d", hour, minute);

    return 0;
}