#include <stdio.h>
#define MAX_VALUE 100
#define MAX_CNT 20
int min(int a, int b)
{
    return a < b ? a : b;
}
int main()
{

    // dp[i]表示面值为i时的最大张数
    int dp[MAX_VALUE + 1];
    for (int i = 0; i <= MAX_VALUE; i++)
    {
        dp[i] = MAX_CNT;
    }
    dp[0] = 0;

    // 邮票面值(升序)
    int stamps[MAX_CNT];
    // 总值,邮票数
    int totalVal,
        stampCnt;
    scanf("%d %d", &totalVal, &stampCnt);
    for (int i = 0; i < stampCnt; i++)
    {
        scanf("%d", &stamps[i]);
    }

    for (int i = 0; i < stampCnt; i++)
    {
        // 设想假如正序的话，现在有一张邮票的价值为1，DP[1] 会使用到1，
        // DP[2] = min(DP[2], DP[1] + 1), 这样就相当于使用了两次
        // 价值为1的邮票，与题意显然不符合，因此第二层循环一定要倒序。
        for (int j = totalVal; j >= 0; j--)
        {
            if (j - stamps[i] >= 0)
            {
                // 选中当前邮票后的总张数 j - stampVal[i] + 1
                dp[j] = min(dp[j], dp[j - stamps[i]] + 1);
            }
        }
    }

    if (dp[totalVal] == MAX_CNT)
    {
        printf("0\n");
    }
    else
    {
        printf("%d", dp[totalVal]);
    }
    return 0;
}