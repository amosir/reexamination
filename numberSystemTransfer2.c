#include <stdio.h>
#define MAX_LEN 20
#define MAX_RADIX_CNT 36
// 获取数字字符对应的十进制数
int getDecimal(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return ch - '0';
    }
    else
    {
        return ch - 'A' + 10;
    }
}
void transfer(char initialNum[], char targerNum[], int initialRadix, int targetRadix)
{
    // 目标数当前所处的位置
    int pos = 0;
    // 填充进制转换表
    char radices[MAX_RADIX_CNT];
    for (int i = 0; i < MAX_RADIX_CNT; i++)
    {
        if (i < 10)
        {
            radices[i] = '0' + i;
        }
        else
        {
            radices[i] = 'A' + (i - 10);
        }
    }

    while (initialNum[0] != '\0')
    {
        // 余数
        int remain = 0;
        for (int i = 0; initialNum[i] != '\0'; i++)
        {
            int temp = remain * initialRadix + getDecimal(initialNum[i]);
            initialNum[i] = radices[temp / targetRadix];
            remain = temp % targetRadix;
        }

        // 最后一位的余数
        targerNum[pos++] = radices[remain];

        // 去掉原数取余后商中前导的0,将数组第一个非0元素移动至首位
        int i = 0;
        while (initialNum[i] == '0')
        {
            i++;
        }
        int j, k;
        for (j = 0, k = i; initialNum[k] != '\0';)
        {
            initialNum[j++] = initialNum[k++];
        }
        initialNum[j] = '\0';
    }
    targerNum[pos] = '\0';

    // 将前面得到的余数逆置
    for (int i = 0, j = pos - 1; i < j; i++, j--)
    {
        targerNum[i] = targerNum[i] ^ targerNum[j];
        targerNum[j] = targerNum[i] ^ targerNum[j];
        targerNum[i] = targerNum[i] ^ targerNum[j];
    }
}
int main()
{
    // 初始进制,目标进制
    int initialRadix, targetRadix;
    char initialNum[MAX_LEN];
    char targetNum[MAX_LEN * 2];
    scanf("%d %d", &initialRadix, &targetRadix);
    scanf("%s", initialNum);
    transfer(initialNum, targetNum, initialRadix, targetRadix);
    printf("%s\n", targetNum);
    return 0;
}