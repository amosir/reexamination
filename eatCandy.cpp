#include <iostream>
using namespace std;
int main()
{
    int dp[20];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < 20; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int candyCnt;
    while (cin >> candyCnt)
    {
        cout << dp[candyCnt] << endl;
    }
    return 0;
}