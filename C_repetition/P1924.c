#include <stdio.h>

int main()
{
    int cal[13] = {0,
                   31,
                   28,
                   31,
                   30,
                   31,
                   30,
                   31,
                   31,
                   30,
                   31,
                   30,
                   31};

    char weekday[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    int month, date, result = 0;
    scanf("%d %d", &month, &date);

    result += date;
    for (int i = 0; i < month; i++)
        result += cal[i];

    for (int i = 0; i < 3; i++)
        printf("%c", weekday[result % 7][i]);

    printf("\n");
    return 0;
}