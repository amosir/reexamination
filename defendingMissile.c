#include <stdio.h>
#define MAX_CNT 25
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    // 导弹数
    int missileCnt;
    scanf("%d", &missileCnt);

    int heights[MAX_CNT];
    for (int i = 0; i < missileCnt; i++)
    {
        scanf("%d", &heights[i]);
    }
    // dp[i]表示heights[i]之前的最长递交子序列的长度
    int dp[MAX_CNT];
    for (int i = 0; i < MAX_CNT; i++)
    {
        dp[i] = 1;
    }

    // 记录最大的dp值
    int maxIndex = 0;

    // 求最长非递增子序列的长度
    for (int i = 0; i < missileCnt; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (heights[j] >= heights[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[maxIndex] < dp[i])
            {
                maxIndex = i;
            }
        }
    }
    printf("%d\n", dp[maxIndex]);
    return 0;
}