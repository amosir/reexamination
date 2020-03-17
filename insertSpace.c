#include <stdio.h>
#define LEN 80
void Insert(char s[]);
int main()
{
    char str[LEN];
    printf("Input a string:\n");
    fgets(str, LEN, stdin);
    Insert(str);
    printf("%s\n", str);
    return 0;
}
void Insert(char s[])
{
    // 字符串长度
    int len = 0;
    // 使用fget输入时如果提前遇到换行会把换行符也保存在字符串中
    // 所以需要判断换行符
    while (s[len] != '\0' && s[len] != '\n')
    {
        len++;
    }

    // n个字符串需要插入n-1个空格，总共2n - 1个长度
    int totalLen = 2 * len - 1;
    s[totalLen] = '\0';

    // 从后面开始移动字符
    for (int i = len - 1, j = totalLen - 1; i >= 0; i--, j--)
    {
        s[j] = s[i];
        // 每移动一个字符插入一个空格,移动最后一个时不插入空格
        if (i != 0)
        {
            s[--j] = ' ';
        }
    }
}