#include <stdio.h>
#define LEN 9
static int days_of_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 比较两个日期,返回1,0,-1
int compare(int year1, int month1, int day1, int year2,
            int month2, int day2)
{
    if ((year1 == year2) && (month1 == month2) && (day1 == day2))
    {
        return 0;
    }
    if (year1 > year2)
    {
        return 1;
    }
    if ((year1 == year2) && (month1 > month2))
    {
        return 1;
    }
    if ((year1 == year2) && (month1 == month2) && (day1 > day2))
    {
        return 1;
    }
    return -1;
}
// 日期1大于日期2
int countDistance(int year1, int month1, int day1, int year2,
                  int month2, int day2)
{
    int distance = 1;
    while (!((year1 == year2) && (month1 == month2) && (day1 == day2)))
    {
        day2++;
        // 单独处理闰年2月
        if ((year2 % 400 == 0) || ((year2 % 4 == 0) && (year2 % 100 != 0)))
        {
            days_of_month[2] = 29;
        }
        // 日期操作当月最多天数则日期置为1,月份加1
        if (day2 > days_of_month[month2])
        {
            day2 = 1;
            month2++;
        }
        // 月份超过12年份加1
        if (month2 > 12)
        {
            month2 = 1;
            year2++;
        }
        distance++;
        days_of_month[2] = 28;
    }
    return distance;
}
int main()
{
    int year1, month1, day1, year2,
        month2, day2;
    scanf("%4d%2d%d", &year1, &month1, &day1);
    scanf("%4d%2d%d", &year2, &month2, &day2);

    if (compare(year1, month1, day1, year2, month2, day2) == 1)
    {
        printf("%d\n", countDistance(year1, month1, day1, year2, month2, day2));
    }
    else if (compare(year1, month1, day1, year2, month2, day2) == -1)
    {
        printf("%d\n", countDistance(year2, month2, day2, year1, month1, day1));
    }
    else
    {
        printf("0\n");
    }
    return 0;
}