#include <stdio.h>
int main()
{
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int year, month, day, temp = 0;
        scanf("%d %d %d", &year, &month, &day);

        // 闰年2月天数
        if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
        {
            days[2] += 1;
        }

        for (int j = 1; j < month; j++)
        {
            temp += days[j];
        }

        temp += day;

        printf("%d\n", temp);

        // 还原
        days[2] = 28;
    }

    return 0;
}