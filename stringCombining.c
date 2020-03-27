#include <stdio.h>
#include <string.h>
#define MAX_LEN 101
int main()
{
    // 待合并字符串
    char str1[MAX_LEN], str2[MAX_LEN];
    // 合并后的字符串
    char combinedStr[MAX_LEN * 2];
    scanf("%s %s", str1, str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    // 字符串1、2的当前位置
    int pos1 = 0;
    int pos2 = len2 - 1;
    int pos3 = 0;
    while (pos1 < len1 && pos2 >= 0)
    {
        combinedStr[pos3++] = str1[pos1++];
        combinedStr[pos3++] = str2[pos2--];
    }
    combinedStr[pos3] = '\0';
    printf("%s\n", combinedStr);
    return 0;
}