#include <stdio.h>
int main()
{
    int cols, rows;
    char ch;
    scanf("%d %c", &cols, &ch);
    if ((cols & 1) == 0)
    {
        rows = cols / 2;
    }
    else
    {
        rows = cols / 2 + 1;
    }
    // 第一行
    for (int i = 0; i < cols; i++)
    {
        printf("%c", ch);
    }
    printf("\n");
    // 2 ~ rows - 1行
    for (int i = 0; i < rows - 2; i++)
    {
        printf("%c", ch);
        for (int j = 0; j < cols - 2; j++)
        {
            printf(" ");
        }
        printf("%c\n", ch);
    }
    // 最后一行
    for (int i = 0; i < cols; i++)
    {
        printf("%c", ch);
    }
    printf("\n");
    return 0;
}