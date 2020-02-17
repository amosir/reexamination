#include <iostream>
#include <vector>
#include<math.h>
using namespace std;
int main(){
    int missileCnt;
    cin >> missileCnt;
    vector<int> heights(missileCnt,0);
    for(int i = 0;i < missileCnt;i++){
        cin >> heights[i];
    }

    // dp[i] 表示前i个导弹所能拦截的最大数量
    vector<int> dp(missileCnt,1);
    int maxIndex = 0;
    for(int i = 0;i < missileCnt;i++){
        for(int j = 0;j < i;j++){
            if(heights[j] >= heights[i]){
                dp[i] = max(dp[i],dp[j] + 1);
            }
            if(dp[i] > dp[maxIndex]){
                maxIndex = i;
            }
        }
    }
    cout << dp[maxIndex] << endl;
}