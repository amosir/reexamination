#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 10
int main()
{
    char str[SIZE][SIZE];
    int index = 0;
    while (scanf("%s", str[index]) == 1)
    {

        // 将全部字符小写化
        for (int i = 0; str[index][i] != '\0'; i++)
        {
            str[index][i] = tolower(str[index][i]);
        }
        // 吸收空格和换行
        if (getchar() == '\n')
        {
            break;
        }
        index++;
    }

    // 字典排序
    for (int i = 1; i <= index; i++)
    {
        for (int j = 0; j < index + 1 - i; j++)
        {
            if (strcmp(str[j], str[j + 1]) > 0)
            {
                char temp[SIZE];
                strcpy(temp, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], temp);
            }
        }
    }

    // 统计个数
    int count = 1;
    for (int i = 1; i <= index; i++)
    {
        if (strcasecmp(str[i], str[i - 1]) == 0)
        {
            count++;
        }
        else
        {
            printf("%s:%d\n", str[i - 1], count);
            count = 1;
        }
    }

    printf("%s:%d\n", str[index], count);

    return 0;
}