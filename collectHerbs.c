#include <stdio.h>
#include <string.h>
#define MAX_TIME 1001
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    // 总时间、药草数量
    int totalTime, herbCnt;
    while (scanf("%d %d", &totalTime, &herbCnt) != EOF)
    {
        // dp[i]表示采药时间为i时的最大价值
        int dp[MAX_TIME];
        memset(dp, 0, MAX_TIME * sizeof(int));
        for (int i = 0; i < herbCnt; i++)
        {
            // 分别表示每种草药的时间和价值
            int singleTime, singleValue;
            scanf("%d %d", &singleTime, &singleValue);
            // 计算每一时间采药的最大价值
            for (int j = totalTime; j >= 0; j--)
            {
                if (j >= singleTime)
                {
                    dp[j] = max(dp[j], dp[j - singleTime] + singleValue);
                }
            }
        }
        printf("%d\n", dp[totalTime]);
    }
}