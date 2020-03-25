#include <stdio.h>
int reverse(int num)
{
    int sum = 0;
    while (num != 0)
    {
        sum = sum * 10 + num % 10;
        num /= 10;
    }
    return sum;
}
int main()
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    if (reverse(num1) + reverse(num2) == reverse(num1 + num2))
    {
        printf("%d\n", num1 + num2);
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}