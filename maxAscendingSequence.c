#include <stdio.h>
#define MAX_CNT 1000
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int cnt;
    scanf("%d", &cnt);
    int nums[MAX_CNT];

    // dp[i]表示nums[i]之前的上升子序列和最大值
    int dp[MAX_CNT];
    for (int i = 0; i < cnt; i++)
    {
        int temp;
        scanf("%d", &temp);
        dp[i] = temp;
        nums[i] = temp;
    }

    // 记录最大dp值
    int maxIndex = 0;
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[j] + nums[i]);
                // 更新最大dp值位置
                if (dp[i] > dp[maxIndex])
                {
                    maxIndex = i;
                }
            }
        }
    }
    printf("%d\n", dp[maxIndex]);
    return 0;
}