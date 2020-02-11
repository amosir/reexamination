#include<iostream>
#include<vector>
using namespace std;
int main(){
    int len;
    while(cin >> len){

        // dp[i] 保存第i个字符之前的子序列的最大值
        vector<int> dp(len);
        vector<int> vec(len);
        for(int i = 0;i < len;i++){
            int temp;
            cin >> temp;
            vec[i] = temp;
            dp[i] = temp;
        }

        for(int i = 1;i < len;i++){
            for(int j = i - 1;j >= 0;j--){
                if(vec[j] < vec[i]){
                    dp[i] = dp[j] + vec[i] > dp[i] ? dp[j] + vec[i] : dp[i];
                }
            }
        }

        // 寻找最大值
        int max = 0;
        for(int i = 1;i < len;i++){
            if(dp[i] > dp[max]){
                max = i;
            }
        }
        cout << dp[max] << endl;
    }
    return 0;

}