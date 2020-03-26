#include <stdio.h>
void MyStrcat(char dstStr[], char srcStr[])
{
    // 寻找dstStr的最后一个字符位置
    int i;
    for (i = 0; dstStr[i] != '\0'; i++)
    {
    }
    for (int j = 0; srcStr[j] != '\0';)
    {
        dstStr[i++] = srcStr[j++];
    }
    srcStr[i] = '\0';
}
int main()
{
    char str1[50], str2[10];
    scanf("%s %s", str1, str2);
    MyStrcat(str1, str2);
    printf("%s\n", str1);
    return 0;
}