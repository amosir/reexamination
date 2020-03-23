#include <stdio.h>
#define LEN 10000
int main()
{
    int num;
    scanf("%d", &num);
    int factorial[LEN];
    for (int i = 0; i < LEN; i++)
    {
        factorial[i] = 0;
    }

    // 任何数的阶乘必定要乘以1
    factorial[0] = 1;

    // 每一个数的阶乘
    for (int i = 2; i <= num; i++)
    {
        int carry = 0;

        // 求阶乘的每一位
        for (int j = 0; j < LEN; j++)
        {
            int temp = factorial[j] * i + carry;
            factorial[j] = temp % 10;
            carry = temp / 10;
        }
    }

    // 从后往前找到第一个不为0的位并开始反向输出
    for (int k = LEN - 1; k >= 0; k--)
    {
        if (factorial[k] != 0)
        {
            while (k >= 0)
            {
                printf("%d", factorial[k--]);
            }
        }
    }
    printf("\n");
    return 0;
}