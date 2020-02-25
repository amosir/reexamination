#include <stdio.h>
int main()
{
    char strtemp[90];
    char str[90][90];

    gets(strtemp);

    // row表示第几个单词，col表示该单词的第几个字符
    int row = 0, col = 0;
    for (int i = 0; strtemp[i] != '\0'; i++)
    {
        // 没遇到空格说明在当前单词
        if (strtemp[i] != ' ')
        {
            str[row][col++] = strtemp[i];
        }
        // 下一个单词
        else
        {
            str[row++][col] = '\0';
            col = 0;
        }
    }
    // 最后一个单词末尾
    str[row][col] = '\0';

    for (int i = row; i >= 0; i--)
    {
        printf("%s", str[i]);
        if (i > 0)
        {
            printf(" ");
        }
    }
    return 0;
}