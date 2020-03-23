#include <stdio.h>
int main()
{
    int dayOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, month, day;
    while (scanf("%d %d %d", &year, &month, &day) != EOF)
    {
        if (1 <= year && year <= 3000 && month >= 1 && month <= 12 && day >= 1 && day <= 31)
        {
            if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
            {
                dayOfMonth[2] = 29;
            }
            for (int i = 1; i < month; i++)
            {
                day += dayOfMonth[i];
            }
            printf("%d\n", day);
            dayOfMonth[2] = 28;
        }
    }
}