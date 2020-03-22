#include <stdio.h>
int getPrimeFactor(int num)
{
    int cnt = 0;

    if (num == 0)
    {
        return cnt;
    }

    // 每次调用都优先使用素数去除
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            // 当前数能整除，则多一个素因子
            // 并且加上除去该因子后剩下数的素因子个数
            cnt += (1 + getPrimeFactor(num / i));
            break;
        }
    }

    // cnt == 0表示当前数没有被任何素数整除，则当前数就是素数
    if (cnt == 0)
    {
        cnt += 1;
    }
    return cnt;
}
int main()
{
    int num;
    scanf("%d", &num);
    printf("%d", getPrimeFactor(num));
    return 0;
}