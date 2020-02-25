#include <stdio.h>
#include <string.h>
int main()
{

    char week[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    char strs[4][90];
    for (int i = 0; i < 4; i++)
    {
        scanf("%s", strs[i]);
    }

    // 前两个字符串第一个相同位置的字符
    int i = 0;
    for (i = 0; i < strlen(strs[0]) && i < strlen(strs[1]); i++)
    {
        if (strs[0][i] >= 'A' && strs[0][i] <= 'G' && strs[0][i] == strs[1][i])
        {
            printf("%s ", week[strs[0][i] - 'A']);
            break;
        }
    }

    // 在上面的基础上找第二个相同位置的 0 ~ 9或A~N
    for (i++; i < strlen(strs[0]) && i < strlen(strs[1]); i++)
    {
        if (strs[0][i] == strs[1][i])
        {
            if (strs[0][i] >= '0' && strs[0][i] <= '9')
            {
                printf("%02d:", strs[0][i] - '0');
                break;
            }
            else if (strs[0][i] >= 'A' && strs[0][i] <= 'N')
            {
                printf("%02d:", strs[0][i] - 'A' + 10);
                break;
            }
        }
    }

    // 在后面两个字符串中找第一个相同的英文字母的位置
    for (i = 0; i < strlen(strs[2]) && i < strlen(strs[3]); i++)
    {
        if (strs[2][i] == strs[3][i])
        {
            if ((strs[2][i] >= 'A' && strs[2][i] <= 'Z') ||
                (strs[2][i] >= 'a' && strs[2][i] <= 'z'))
            {
                printf("%02d", i);
                break;
            }
        }
    }
    return 0;
}