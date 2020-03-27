#include <stdio.h>
int main()
{
    int num;
    while (scanf("%d", &num) != EOF)
    {
        // 是否是守形数
        int flag = 1;
        // 平方
        int squareOfNum = num * num;
        while (num != 0)
        {
            if (num % 10 != squareOfNum % 10)
            {
                // 不是守形数
                flag = 0;
                break;
            }
            else
            {
                num /= 10;
                squareOfNum /= 10;
            }
        }
        if (flag == 0)
        {
            printf("No!");
        }
        else
        {
            printf("Yes!");
        }
    }
    return 0;
}