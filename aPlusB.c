#include <stdio.h>
#include <string.h>
#define MAX_LEN 1001
int main()
{
    // 分别存放待求和的两个数和计算结果
    char num1[MAX_LEN], num2[MAX_LEN], result[MAX_LEN + 1];
    while (scanf("%s %s", num1, num2) != EOF)
    {
        int pos = 0;
        // 吸收换行符
        getchar();
        int len1 = strlen(num1);
        int len2 = strlen(num2);

        // 进位
        int carry = 0;
        int i = len1 - 1, j = len2 - 1;
        // 从后往前相加
        while (i >= 0 && j >= 0)
        {
            // 本位和与进位之和,由于使用的是字符数组，所以要注意转换
            int temp = (num1[i--] - '0') + (num2[j--] - '0') + carry;
            carry = temp / 10;
            result[pos++] = temp % 10 + '0';
        }

        // num2位数较多的情况
        while (j >= 0)
        {
            int temp = (num2[j--] - '0') + carry;
            carry = temp / 10;
            result[pos++] = temp % 10 + '0';
        }

        // num1位数较多的情况
        while (i >= 0)
        {
            int temp = (num1[i--] - '0') + carry;
            carry = temp / 10;
            result[pos++] = temp % 10 + '0';
        }

        // 最高位的进位
        if (carry != 0)
        {
            result[pos++] = carry + '0';
        }
        // 加的时候从低位到高位，输出则反序
        while (--pos >= 0)
        {
            printf("%c", result[pos]);
        }
        printf("\n");
    }
    return 0;
}