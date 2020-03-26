#include <stdio.h>
int isPrime(int num)
{
    // 0,1和负数都是非素数
    if (num <= 1)
    {
        return 0;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int num;
    scanf("%d", &num);
    printf("%s\n", isPrime(num) == 1 ? "yes" : "no");
    return 0;
}