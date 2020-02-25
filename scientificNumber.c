#include <stdio.h>
#include <string.h>
int main()
{
    char num[10000];
    scanf("%s", num);
    // 长度
    int len = strlen(num);
    if (num[0] == '-')
    {
        printf("-");
    }
    // 找e的位置
    int e_pos = 1;
    while (num[e_pos] != 'E')
    {
        e_pos++;
    }

    // 指数
    int exp = 0;
    for (int i = e_pos + 2; i < len; i++)
    {
        exp = exp * 10 + (num[i] - '0');
    }

    // 指数为0
    if (exp == 0)
    {
        for (int j = 1; j < e_pos; j++)
        {
            printf("%c", num[j]);
        }
    }

    // 指数为负
    if (num[e_pos + 1] == '-')
    {
        printf("0.");
        for (int i = 0; i < exp - 1; i++)
        {
            printf("0");
        }
        printf("%c", num[1]);
        for (int i = 3; i < e_pos; i++)
        {
            printf("%c", num[i]);
        }
    }
    else
    {
        for (int i = 1; i < e_pos; i++)
        {

            // 跳过原本的小数点
            if (num[i] == '.')
            {
                continue;
            }
            printf("%c", num[i]);

            // 原本小数点位置在i = 2处，移动后小数点在 pos + 2 处
            // 当e_pos - 3 == exp时小数点在最后，不用显示
            if (i == exp + 2 && e_pos - 3 != exp)
            {
                printf(".");
            }
        }
        // 显示后面的0
        for (int i = 0; i < exp - (e_pos - 3); i++)
        {
            printf("0");
        }
    }
    return 0;
}