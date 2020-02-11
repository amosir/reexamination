#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // 总值,邮票数
    int totalVal, stampCnt;

    cin >> totalVal >> stampCnt;

    // 每张邮票的面值
    vector<int> stampVal(stampCnt);

    for (int i = 0; i < stampCnt; i++)
    {
        cin >> stampVal[i];
    }

    // dp[i]表示能凑成总值为i的邮票的最小数
    vector<int> dp(totalVal + 1, stampCnt + 1);
    dp[0] = 0;
    for (int i = 0; i < stampCnt; i++)
    {

        // 设想假如正序的话，现在有一张邮票的价值为1，DP[1] 会使用到1，
        // DP[2] = min(DP[2], DP[1] + 1), 这样就相当于使用了两次
        // 价值为1的邮票，与题意显然不符合，因此第二层循环一定要倒序。
        for (int j = totalVal; j >= 0; j--)
        {
            // 选中当前邮票后的总张数 j - stampVal[i] + 1
            if (j - stampVal[i] >= 0 && dp[j] > dp[j - stampVal[i]] + 1)
            {
                dp[j] = dp[j - stampVal[i]] + 1;
            }
        }
    }

    if (dp[totalVal] == stampCnt + 1)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << dp[totalVal] << endl;
    }
    return 0;
}