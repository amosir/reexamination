#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>
using namespace std;

// 获取某一行元素的最大子数组最大和
int getRowMaxSum(vector<int> &vec){
    // dp[i]表示以第i个字符结尾的最大和
    vector<int> dp(vec.size());
    dp[0] = vec[0];
    int maxSum = dp[0];
    for(int i = 1;i < vec.size();i++){
        dp[i] = max(dp[i - 1] + vec[i],vec[i]);
        if(dp[i] > maxSum){
            maxSum = dp[i];
        }
    }
    return maxSum;
}
int getMaxSubMatrix(vector<vector<int> > &vec){
    int maxSum = INT_MIN;

    // 从第一行开始，求每一行的最大子数组和
    // 然后将其与后面几行对应位置相加，在构成的新行
    // 中求最大子数组和
    for(int i = 0;i < vec.size();i++){
        vector<int> temp(vec.size(),0);
        // 后面几行
        for(int j = i;j < vec.size();j++){
            // 对应位置相加
            for(int k = 0;k < vec[i].size();k++){
                temp[k] += vec[j][k];
            }

            // 将上面的行和下面的行对应位置相加，求新行的最大子数组和
            maxSum = max(maxSum,getRowMaxSum(temp));
        }
    }
    return maxSum;
}
int main(){
    int rows;
    while(cin >> rows){
        vector<vector<int> > matrix(rows,vector<int>(rows,0));
        for(int i = 0;i < rows;i++){
            for(int j = 0;j < rows;j++){
                cin >> matrix[i][j];
            }
        }
        cout << getMaxSubMatrix(matrix) << endl;
    }
    return 0;
}