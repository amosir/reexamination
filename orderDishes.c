#include <stdio.h>
#include <string.h>
#define MOST_MONEY 1000
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    // 总共能报销的钱数和点菜总数
    int totalMoney, dishCnt;
    while (scanf("%d %d", &totalMoney, &dishCnt) != EOF)
    {
        // dp[i]表示总共报销价钱为i时的最大评价分数
        int dp[MOST_MONEY + 1];
        // 初试化为0
        memset(dp, 0, (MOST_MONEY + 1) * sizeof(int));
        // 每加入一种菜就计算最大评价数
        for (int i = 0; i < dishCnt; i++)
        {
            int price, comment;
            scanf("%d %d", &price, &comment);
            for (int j = totalMoney; j >= 0; j--)
            {
                if (j >= price)
                {
                    dp[j] = max(dp[j], dp[j - price] + comment);
                }
            }
        }
        printf("%d\n", dp[totalMoney]);
    }
    return 0;
}
