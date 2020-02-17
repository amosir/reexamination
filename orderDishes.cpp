#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main(){
    int totalMoney,dishCnt;
    while(cin >> totalMoney >> dishCnt){
        // dp[i]表示钱数为i时的最大评价
        vector<int> dp(totalMoney + 1,0);

        // 一次加一种菜，每加入一种菜就计算加入后
        // 不同钱数所买菜的评价的最大值
        for(int i = 1;i <= dishCnt;i++){
            // 每种菜的价格和评价
            int price,comment;
            cin >> price >> comment;
            for(int j = totalMoney;j >= 0;j--){
                // 剩余钱数能买该种菜
                if(j >= price){
                    dp[j] = max(dp[j],dp[j - price] + comment);
                }
            }
        }
        cout << dp[totalMoney] << endl;
    }
    return 0;
}