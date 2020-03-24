#include <stdio.h>
int main()
{
    int goodsCnt;
    int goodVolumes[20];
    // dp[i][j]表示用前i件物品凑出体积为j的方案数
    int dp[21][41];

    // 初始化
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 41; j++)
        {
            dp[i][j] = 0;
        }
    }

    // base case
    for (int i = 0; i < 21; i++)
    {
        dp[i][0] = 1;
    }

    //物品的体积
    scanf("%d", &goodsCnt);
    for (int i = 0; i < goodsCnt; i++)
    {
        scanf("%d", &goodVolumes[i]);
    }

    for (int i = 1; i <= goodsCnt; i++)
    {
        for (int j = 1; j < 41; j++)
        {
            if (j < goodVolumes[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - goodVolumes[i - 1]];
            }
        }
    }
    printf("%d\n", dp[goodsCnt][40]);
    return 0;
}