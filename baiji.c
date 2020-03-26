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