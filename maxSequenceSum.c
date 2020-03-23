#include <stdio.h>
#define MAX_LEN 1000000
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int cnt;
    scanf("%d", &cnt);

    // dp[i]表示以nums[i]结束的最大子串和
    int dp[MAX_LEN];

    // 输入的数组序列
    int nums[MAX_LEN];
    for (int i = 0; i < cnt; i++)
    {
        scanf("%d", &nums[i]);
    }
    for (int j = 0; j < cnt; j++)
    {
        if (j == 0)
        {
            dp[j] = nums[j];
            continue;
        }
        // 是当前单独一个字符的和大
        // 还是将当前字符加入前面的子串得到的和大
        dp[j] = max(dp[j - 1] + nums[j], nums[j]);
    }

    int maxIndex = 0;
    for (int k = 1; k < cnt; k++)
    {
        if (dp[k] > dp[maxIndex])
        {
            maxIndex = k;
        }
    }
    printf("%d\n", dp[maxIndex]);
    return 0;
}