#include <stdio.h>
#include <ctype.h>
#define MAX_LEN 80

int main()
{
    char str[MAX_LEN];

    // fgets如果提前输入结束会存入换行符
    fgets(str, MAX_LEN, stdin);
    int i;
    for (i = 0; str[i] != '\n' && str[i] != '\0'; i++)
    {
        if (isalpha(str[i]))
        {
            if (str[i] == 'z')
            {
                str[i] = 'a';
                continue;
            }
            if (str[i] == 'Z')
            {
                str[i] = 'A';
                continue;
            }
            str[i] = str[i] + 1;
        }
    }

    // 将换行符置为空字符
    str[i] = '\0';

    printf("%s\n", str);
    return 0;
}