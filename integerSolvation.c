#include <stdio.h>
#define SIZE 1000000
#define MOD 1000000000
int main()
{
    int num;
    scanf("%d", &num);
    int dp[SIZE];

    // dp[i]表示前i个数的分解方案数
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= num; i++)
    {

        // 当前数是偶数时,有包含1和不包含1两种
        if (i % 2 == 0)
        {
            dp[i] = (dp[i - 1] + dp[i / 2]) % MOD;
        }

        // 当前数是奇数时一定包含一个1，去掉1划分方式不变
        else
        {
            dp[i] = dp[i - 1];
        }
    }
    printf("%d\n", dp[num]);
    return 0;
}