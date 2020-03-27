#include <stdio.h>
#include <string.h>
#define MAX_LEN 101
int main()
{
    char str[MAX_LEN];

    // flag用于标记str[i]是否输出过
    int flag;
    while (scanf("%s", str) != EOF)
    {
        int len = strlen(str);
        for (int i = 0; i < len; i++)
        {
            flag = 0;
            for (int j = i + 1; j < len; j++)
            {
                if (str[i] == str[j] && str[i] != '*')
                {
                    // 如果没有输出过,那么两个位置都要输出并且flag置为1
                    if (flag == 0)
                    {
                        printf("%c:%d,%c:%d", str[i], i, str[j], j);
                        flag = 1;
                    }
                    // 如果输出过,那么只需要输出后出现的那个即可
                    else
                    {
                        printf(",%c:%d", str[j], j);
                    }

                    // 将重复的位置替换掉，避免后面重复输出
                    str[j] = '*';
                }
            }
            if (flag == 1)
            {
                printf("\n");
            }
        }
        return 0;
    }
}