#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int cnt;
    while (cin >> cnt)
    {
        vector<int> nums;
        vector<int> dp(cnt);
        for (int i = 0; i < cnt; i++)
        {
            int temp;
            cin >> temp;
            nums.push_back(temp);
        }
        for (int j = 0; j < cnt; j++)
        {
            if (j == 0)
            {
                dp[0] = nums[0];
            }
            else
            {
                dp[j] = nums[j] + dp[j - 1] > nums[j] ? nums[j] + dp[j - 1] : nums[j];
            }
        }
        int max = 0;
        for (int k = 1; k < cnt; k++)
        {
            if (dp[max] < dp[k])
            {
                max = k;
            }
        }
        cout << dp[max];
    }
    return 0;
}