#include <stdio.h>
#include <string.h>
#define LEN 17
// 将十进制数转化为16位的二进制
void decimal2bits(int num, char bits[])
{
    // 临时索引
    int index = 0;
    // 求余数
    while (num != 0)
    {
        bits[index++] = num % 2 + '0';
        num /= 2;
    }
    // 不够16位填0
    while (index < LEN - 1)
    {
        bits[index++] = '0';
    }

    // 逆置后才是真正的2进制表示
    for (int i = 0, j = LEN - 2; i < j; i++, j--)
    {
        bits[i] = bits[j] ^ bits[i];
        bits[j] = bits[j] ^ bits[i];
        bits[i] = bits[j] ^ bits[i];
    }
    // 字符串尾部结束符
    bits[index] = '\0';
}
// 循环左移一位
void circularShiftLeft(char bits[])
{
    char firstChar = bits[0];
    int i;
    for (i = 1; bits[i] != '\0'; i++)
    {
        bits[i - 1] = bits[i];
    }
    bits[i - 1] = firstChar;
}
int main()
{
    int num1, num2;
    while (scanf("%d %d", &num1, &num2) != EOF)
    {
        if (num1 == num2)
        {
            printf("YES\n");
        }
        else
        {
            char num1_bits[LEN], num2_bits[LEN];
            // 转化为16为二进制数
            decimal2bits(num1, num1_bits);
            decimal2bits(num2, num2_bits);

            // 记录循环移位次数
            int i;
            for (i = 0; i < LEN - 1; i++)
            {

                // 循环移位1次
                circularShiftLeft(num1_bits);
                // 移位后相等直接跳出
                if (strcmp(num1_bits, num2_bits) == 0)
                {
                    printf("YES\n");
                    break;
                }
            }
            // 循环移位16次表示不能通过移位得到
            if (i == LEN - 1)
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}