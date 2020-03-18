#include <stdio.h>
#define MOD 1000000007
#define LEN 100001
int main()
{
    //  原始的字符串
    char str[LEN];
    scanf("%s", str);

    // leftP[i]表示第i位结尾的字符串中P的个数
    int leftP[LEN] = {0};

    int count = 0;

    // 第i个位置结尾的字符串中P的个数
    int i = 0;
    for (; str[i] != '\0'; i++)
    {
        if (i > 0)
        {
            leftP[i] = leftP[i - 1];
        }

        // 当前位是P时才加1
        if (str[i] == 'P')
        {
            leftP[i]++;
        }
    }

    // i是字符串实际长度
    i--;
    // countOfT表示T的个数
    int countOfT = 0;
    for (; i >= 0; i--)
    {
        if (str[i] == 'T')
        {
            countOfT++;
        }
        else if (str[i] == 'A')
        {
            //  这里应该用leftP[i - 1]，但实际上当前位为T时
            // leftP[i - 1]  = leftP[i]，这样写可以避免边界检查
            count = (count + countOfT * leftP[i]) % MOD;
        }
    }

    printf("%d\n", count);
    return 0;
}