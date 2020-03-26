#include <stdio.h>
#include <string.h>
#define MAX_LEN 100
// 冒泡排序(按字典序)
void sort(char str[][MAX_LEN], int len)
{
    for (int i = 1; i <= len - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < len - i; j++)
        {
            if (strcmp(str[j], str[j + 1]) > 0)
            {

                char temp[MAX_LEN];
                strcpy(temp, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], temp);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            return;
        }
    }
}
int main()
{
    //  分别保存原字符串和后缀
    char str[MAX_LEN], postFix[MAX_LEN][MAX_LEN];
    int subIndex = 0;
    fgets(str, MAX_LEN, stdin);

    // 这里不能用strlen判断长度,因为使用fgets输入的字符串
    // 如果没有输入参数指定的长度,会录入换行符
    int len = 0;
    while (str[len] != '\n' && str[len] != '\0')
    {
        len++;
    }
    str[len] = '\0';

    // 后缀开始索引
    for (int i = len - 1; i >= 0; i--)
    {
        // 这里不要使用strncpy，这个函数不会复制'\0',容易导致乱码
        strcpy(postFix[subIndex++], &str[i]);
    }
    sort(postFix, subIndex);
    for (int i = 0; i < subIndex; i++)
    {
        printf("%s\n", postFix[i]);
    }

    return 0;
}