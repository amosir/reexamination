#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main(){

    // 学生数量
    int studentCnt;
    while(cin >> studentCnt && studentCnt != 0){
        // 学生身高
        vector<int> heights(studentCnt,0);
        for(int i = 0;i < studentCnt;i++){
            cin >> heights[i];
        }

        // leftDp[i]表示i之前的最大递增序列
        // rightDp[i]表示之后的最大递减序列
        vector<int> leftDp(studentCnt,1);
        vector<int> rightDp(studentCnt,1);

        for(int i = 0;i < studentCnt;i++){
            for(int j = 0;j < i;j++){

                // 计算i之前的最长递增序列
                if(heights[j] < heights[i]){
                    leftDp[i] = max(leftDp[i],leftDp[j] + 1);
                }

                // 计算i之后的最长递减序列
                // x位置在y前面
                int x = studentCnt - i - 1;
                int y = studentCnt - j - 1;
                if(heights[x] > heights[y]){
                    rightDp[x] = max(rightDp[x],rightDp[y] + 1);
                }
            }
        }

        // 计算每一个位置前面的递增序列长度和后面的递减序列长度之和
        // 值最大时出列的学生数最少
        int maxSum = leftDp[0] + rightDp[0];
        for(int k = 1;k < studentCnt;k++){
            if(leftDp[k] + rightDp[k] > maxSum){
                maxSum = leftDp[k] + rightDp[k];
            }
        }
        // studentCnt - (maxSum - 1) 减掉1是因为位置i即在递增序列，也在递减序列，加了两次
        cout << studentCnt - maxSum + 1 << endl;
    }
}