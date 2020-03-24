#include <stdio.h>
#include <string.h>
#define ALPHA_CNT 26
// 字典排序
void sortFromA2Z(char str[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (str[j] < str[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            str[i] = str[i] ^ str[min];
            str[min] = str[min] ^ str[i];
            str[i] = str[i] ^ str[min];
        }
    }
}
// 全排列字符串、当前全排列位置、访问标记数组、结果数组
void permutation(char str[], int pos, int visited[], char result[])
{
    int len = strlen(str);
    // 全排列结束
    if (pos == len)
    {
        // 输出一个结果
        result[pos] = '\0';
        printf("%s\n", result);
        return;
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            //没有访问过
            if (visited[str[i] - 'a'] == 0)
            {
                // 设置访问标记
                visited[str[i] - 'a'] = 1;
                // 添加到结果
                result[pos] = str[i];

                // 选取下一位置的字符
                permutation(str, pos + 1, visited, result);

                // 还原当前位置
                visited[str[i] - 'a'] = 0;
                result[pos] = '\0';
            }
        }
    }
}
int main()
{
    char str[ALPHA_CNT], result[ALPHA_CNT];

    // 标记数组
    int visited[ALPHA_CNT];
    for (int i = 0; i < ALPHA_CNT; i++)
    {
        visited[i] = 0;
    }

    scanf("%s", str);
    sortFromA2Z(str, strlen(str));

    permutation(str, 0, visited, result);

    printf("\n");

    return 0;
}