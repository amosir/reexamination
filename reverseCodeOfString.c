#include <stdio.h>
#define MAX_LEN 81
int main()
{
    char str[MAX_LEN];
    while (fgets(str, MAX_LEN, stdin))
    {
        // 处理字符串中的换行符
        int i;
        for (i = 0; str[i] != '\0' && str[i] != '\n'; i++)
        {
        }
        str[i] = '\0';
        if (str[0] == '!' && str[1] == '\0')
        {
            return 0;
        }
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = 'z' - (str[i] - 'a');
            }
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] = 'Z' - (str[i] - 'A');
            }
        }
        printf("%s\n", str);
    }
    return 0;
}