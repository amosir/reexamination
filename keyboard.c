#include <stdio.h>
#define LEN 101
int main()
{
    // 每个字母按的次数
    int keys[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
    char str[LEN];
    scanf("%s", str);
    int cnt = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        // 按的时间
        cnt += keys[str[i] - 'a'];
        // 等待时间
        if (i > 0 && (str[i] - str[i - 1] == keys[str[i] - 'a'] - keys[str[i - 1] - 'a']))
        {
            cnt += 2;
        }
    }
    printf("%d\n", cnt);
    return 0;
}