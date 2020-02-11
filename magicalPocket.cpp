#include <iostream>
#include <vector>
using namespace std;

// 递归方式
int count_v1(int i, vector<int> &vec, int leftVolumn)
{
    if (leftVolumn == 0)
    {
        return 1;
    }
    if (i == vec.size() || leftVolumn < 0)
    {
        return 0;
    }
    // count_v1(i,vec,leftVolumn) 表示从第i个物品开始，剩下的容量为
    // leftVolumn
    //  包括选中当前物品和不选中当前物品两种情况
    return count_v1(i + 1, vec, leftVolumn) +
           count_v1(i + 1, vec, leftVolumn - vec[i]);
}

// 动态规划方式
int count_v2(vector<int> &vec)
{
    // dp[i] 表示口袋容积为i时有多少种方式
    vector<int> dp(41, 0);
    dp[0] = 1;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 40; j >= vec[i]; j--)
        {
            dp[j] += dp[j - vec[i]];
        }
    }
    return dp[40];
}
int main()
{
    int wantedCnt;
    cin >> wantedCnt;
    vector<int> goodVolumn(wantedCnt);
    for (int i = 0; i < wantedCnt; i++)
    {
        cin >> goodVolumn[i];
    }
    //cout << count_v1(0, goodVolumn, 40) << endl;
    cout << count_v2(goodVolumn) << endl;
    return 0;
}