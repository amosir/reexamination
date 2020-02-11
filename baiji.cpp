// 用小于等于n元去买100只鸡，大鸡5元/只，小鸡3元/只,还有1/3元每只的一种小鸡，分别记为x只,y只,z只。编程求解x,y,z所有可能解。

#include <stdio.h>
int main()
{
    int n;

    scanf("%d", &n);

    int maxBig = n / 5;
    int maxMedium = n / 3;
    int maxSmall = 3 * n;

    for (int i = 0; i <= maxBig; i++)
    {
        for (int j = 0; j <= maxMedium; j++)
        {
            if (5 * i + 3 * j + (1.0 / 3) * (100 - i - j) <= n)
            {
                printf("x=%d,y=%d,z=%d\n", i, j, 100 - i - j);
            }
        }
    }
    return 0;
}