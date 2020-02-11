// 输出去除指定字符串之后的字符串
#include <stdio.h>

int main()
{

    char arr[200];
    char ch;

    scanf("%s %c", arr, &ch);

    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == ch)
        {
            int j = i;
            for (; arr[j] != '\0'; j++)
            {
                arr[j] = arr[j + 1];
            }
            i--;
            arr[j--] = '\0';
        }
    }

    printf("%s\n", arr);

    return 0;
}