#include <stdio.h>
#define SIZE 20
int main()
{
    // dp[i]表示i块糖果有dp[i]种吃法
    int dp[SIZE];
    int cnt;
    scanf("%d", &cnt);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < cnt; i++)
    {
        // 最后一天可以吃1块或2块
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    printf("%d\n", dp[cnt]);
    return 0;
}