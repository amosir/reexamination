// 输出去除指定字符串之后的字符串
#include <stdio.h>

int main()
{
    char arr[100];
    char ch;

    scanf("%s %c", arr, &ch);

    // i指向当前处理的字符,j指向上一个不是指定字符的字符
    int i, j;
    for (i = 0, j = -1; arr[i] != '\0'; i++)
    {
        if (arr[i] != ch)
        {
            arr[++j] = arr[i];
        }
    }
    arr[++j] = '\0';

    printf("%s\n", arr);

    return 0;
}