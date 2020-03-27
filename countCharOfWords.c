#include <stdio.h>
#define MAX_LEN 100
int main()
{
    char str[MAX_LEN];
    fgets(str, MAX_LEN, stdin);
    // start和end分别指向一个单词的开始和结束
    for (int start = 0, end = 0; str[end] != '\n' && str[end] != '\0';)
    {
        // end一直加直到遇到空格或句点,表示一个单词结束
        if (str[end] != ' ' && str[end] != '.')
        {
            end++;
        }
        else
        {
            printf("%d ", end - start);
            // 跳过中间连续的几个空格
            while (str[end] == ' ' || str[end] == '.')
            {
                end++;
            }
            // 新的单词开始
            start = end;
        }
    }
    printf("\n");
    return 0;
}