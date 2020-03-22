#include <stdio.h>
int main()
{
    // 总数
    int total = 0;
    scanf("%d", &total);
    for (int i = 0; i < total; i++)
    {
        // 约数个数
        int cnt = 0;
        int temp;
        scanf("%d", &temp);
        // 约数从1开始
        for (int j = 1; j * j <= temp; j++)
        {
            if (temp % j == 0)
            {
                // 2 * 2 = 4,2只需要算一次
                if (j * j == temp)
                {
                    cnt += 1;
                }
                else
                {
                    cnt += 2;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}