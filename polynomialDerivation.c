#include <stdio.h>
int main()
{
    // 索引为指数，值为系数
    int coefs[1001] = {0};
    // 系数、指数、count记录指数不为0的箱数
    int k, c, count = 0;
    // linux下 ctrl D再回车
    // windows下Ctrl Z再回车
    while (scanf("%d %d", &k, &c) != EOF)
    {
        coefs[c] = k;
    }

    // 0次项求导为0
    coefs[0] = 0;
    for (int i = 1; i <= 1000; i++)
    {
        coefs[i - 1] = coefs[i] * i;
        if (coefs[i - 1] != 0)
        {
            count++;
        }
    }

    coefs[1000] = 0;

    if (count == 0)
    {
        printf("0 0\n");
    }
    else
    {
        for (int i = 1000; i >= 0; i--)
        {
            if (coefs[i] != 0)
            {
                printf("%d %d", coefs[i], i);
                count--;
                if (count != 0)
                {
                    printf(" ");
                }
            }
        }
    }

    return 0;
}