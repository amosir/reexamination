#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main(){
    // 总时间、药草数量
    int totalTime,herbCnt;
    while(cin >> totalTime >> herbCnt && totalTime!= 0 && herbCnt != 0){

        // dp[i]表示时间为i时能采药的最大价值
        vector<int> dp(totalTime + 1,0);

        // 分别表示每种草药的时间和价值
        int singleTime,singleValue;
        for(int i = 0;i < herbCnt;i++){
            cin >> singleTime >> singleValue;

            // 计算每一时间采药的最大价值
            for(int j = totalTime;j >= 0;j--){
                if(j >= singleTime){
                    dp[j] = max(dp[j],dp[j - singleTime] + singleValue);
                }
            }
        }
        cout << dp[totalTime] << endl;
    }
    return 0;
}