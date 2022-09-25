#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int A, B, time;

int main()
{
    scanf("%d %d", &A, &B);
    scanf(" %d", &time);

    int share, remainder;

    share = time / 60;
    remainder = time % 60;

    printf("%d ", (A + share) < 24 ? (A + share) : (A + share) - 24);
    printf("%d ", (A + remainder) < 60 ? (A + remainder) : (A + remainder) - 60);

    return 0;
}