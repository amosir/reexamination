#include <stdio.h>
static int daysOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    int cnt;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++)
    {
        int year, month, day;
        scanf("%d %d %d", &year, &month, &day);
        // 当天不是该月的最后一天
        if (day + 1 <= daysOfMonth[month])
        {
            day += 1;
        }
        else
        {
            day = 1;
            // 当月不是12月
            if (month + 1 <= 12)
            {
                month += 1;
            }
            else
            {
                month = 1;
                year += 1;
            }
        }
        printf("%4d-%02d-%02d\n", year, month, day);
    }
    return 0;
}