#include <stdio.h>
int gcd(int num1, int num2)
{
    int time = 1;
    if (num1 < num2)
    {
        num1 = num1 ^ num2;
        num2 = num2 ^ num1;
        num1 = num1 ^ num2;
    }
    while (num2 != 0)
    {
        int temp = num1 % num2;
        num1 = num2;
        num2 = temp;
    }
    return num1;
}
int main()
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    printf("%d\n", gcd(num1, num2));
    return 0;
}