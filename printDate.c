#include <stdio.h>
int main()
{
    int days[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // 年份、第几天
    int y, n;
    while (scanf("%d %d", &y, &n) != EOF)
    {
        // 闰年
        if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
        {
            days[2] += 1;
        }
        for (int month = 1; month <= 12; month++)
        {
            if (n > days[month])
            {
                n -= days[month];
            }
            else
            {
                printf("%04d-%02d-%02d\n", y, month, n);
                break;
            }
        }
    }

    return 0;
}