#include <stdio.h>
#include <string.h>
#define MAX_LEN 1001
int main()
{
    char str[MAX_LEN];
    while (scanf("%s", str) != EOF)
    {
        getchar();
        // 是否是回文串
        int flag = 1;
        int len = strlen(str);
        for (int left = 0, right = len - 1; left < right; left++, right--)
        {
            if (str[left] != str[right])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
        {
            printf("No!\n");
        }
        else
        {
            printf("Yes!\n");
        }
    }
    return 0;
}