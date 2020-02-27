#include <stdio.h>
#include <string.h>
// 转置字符串
void reverse(char *str, int len)
{
    int left = 0, right = len - 1;
    while (left < right)
    {
        str[left] = str[left] ^ str[right];
        str[right] = str[right] ^ str[left];
        str[left] = str[left] ^ str[right];
        left++;
        right--;
    }
}
int main()
{
    // 行数、最长后缀
    int lines, maxPostfix = 0;
    char strs[100][256];
    scanf("%d", &lines);
    // 接收换行符
    getchar();
    for (int i = 0; i < lines; i++)
    {
        gets(strs[i]);
        reverse(strs[i], strlen(strs[i]));
    }

    // 第j个字符
    for (int j = 0; j < 256; j++)
    {
        char ch = strs[0][j];
        int same = 1;

        // 每一句话比较第j个字符
        for (int k = 1; k < lines; k++)
        {
            if (ch != strs[k][j])
            {
                same = 0;
                break;
            }
        }
        // 所有的句子第j个字符都相等
        if (same == 1)
        {
            maxPostfix++;
        }
        else
        {
            break;
        }
    }

    // 输出最长后缀
    if (maxPostfix > 0)
    {
        for (int i = maxPostfix - 1; i >= 0; i--)
        {
            printf("%c", strs[0][i]);
        }
        printf("\n");
    }
    else
    {
        printf("nai\n");
    }
    return 0;
}