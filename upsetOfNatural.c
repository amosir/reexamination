#include <stdio.h>
int containsSix(int num)
{
    //是否含有6
    int flag = 0;
    while (num != 0 && flag != 1)
    {
        if (num % 10 == 6)
        {
            flag = 1;
        }
        else
        {
            num /= 10;
        }
    }
    return flag;
}
int main()
{
    int n;
    double result = 0;
    printf("Input n(0 < n < 1000)\n");
    scanf("%d", &n);
    for (int i = 6; i <= n; i++)
    {
        if (containsSix(i))
        {
            result += (1.0 / i);
        }
    }
    printf("%.2f\n", result);
    return 0;
}