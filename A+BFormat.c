#include <stdio.h>
int main()
{
    int num1, num2, sum;
    char ch[7];
    scanf("%d %d", &num1, &num2);
    sum = num1 + num2;
    if (sum < 0)
    {
        printf("-");
        sum = -sum;
    }

    if (sum == 0)
    {
        printf("0");
        return 0;
    }

    int len = 0;
    while (sum)
    {
        ch[len++] = sum % 10 + '0';
        sum /= 10;
    }

    for (int i = len - 1, k = 1; i >= 0; i--)
    {
        printf("%c", ch[i]);
        if (k % 3 == 0 && i > 0)
        {
            printf(",");
            k = 1;
        }
        else
        {
            k++;
        }
    }
    return 0;
}