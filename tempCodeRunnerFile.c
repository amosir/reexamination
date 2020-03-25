#include <stdio.h>
#include <string.h>
#define MAX_LEN 100
#define MAX_CNT 50
void sortAndPrint(char strs[][MAX_LEN], int cnt)
{
    // 排序
    for (int i = 1; i <= cnt - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < cnt - i; j++)
        {
            if(strlen(strs[j]) > strlen(strs[j + 1])){
                char temp[MAX_LEN];
                strcpy(temp, strs[j]);
                strcpy(strs[j], strs[j + 1]);
                strcpy(strs[j + 1], temp);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }

    for (int i = 0; i < cnt; i++)
    {
        printf("%s\n", strs[i]);
    }
}
int main()
{
    int cnt, stoped = 0;
    while (scanf("%d", &cnt) != EOF && !stoped)
    {
        getchar();
        char strs[MAX_CNT][MAX_LEN];
        int i;
        for (i = 0; i < cnt; i++)
        {
            gets(strs[i]);
            if (strcmp(strs[i], "stop") == 0)
            {
                stoped = 1;
                break;
            }
        }
        sortAndPrint(strs, cnt > i ? i : cnt);
    }
    return 0;
}