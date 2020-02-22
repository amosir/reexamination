#include <stdio.h>
#include <math.h>
// 设一个沙漏是n行，则共有2n - 1行，共 2n^2 - 1个符号
int main()
{
    int totalChar;
    char ch;
    scanf("%d %c", &totalChar, &ch);
    // 倒三角的行数
    int rows = (int)sqrt((totalChar + 1) / 2.0);

    int bottomChars = 2 * rows - 1;
    // 倒三角
    for (int i = bottomChars; i >= 1; i -= 2)
    {
        // 左边空格
        for (int j = 0; j < (bottomChars - i) / 2; j++)
        {
            printf(" ");
        }

        // 符号
        for (int j = 0; j < i; j++)
        {
            printf("%c", ch);
        }

        // 右边空格
        for (int j = 0; j < (bottomChars - i) / 2; j++)
        {
            printf(" ");
        }
        printf("\n");
    }

    // 正三角
    for (int i = 3; i <= bottomChars; i += 2)
    {
        for (int j = 0; j < (bottomChars - i) / 2; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("%c", ch);
        }
        for (int j = 0; j < (bottomChars - i) / 2; j++)
        {
            printf(" ");
        }
        printf("\n");
    }

    printf("%d\n", totalChar - 2 * rows * rows + 1);
    return 0;
}