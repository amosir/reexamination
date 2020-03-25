#include <stdio.h>
#include <string.h>
#include <limits.h>
#define N 100
// 求最大值
int max(int a, int b)
{
    return a > b ? a : b;
}
// 一维数组求最大子数组和
int maxSubArraySum(int nums[], int len)
{
    // dp[i]表示以nums[i]结尾的子数组最大和
    int dp[N];
    dp[0] = nums[0];
    int maxSum = dp[0];
    for (int i = 1; i < len; i++)
    {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        if (maxSum < dp[i])
        {
            maxSum = dp[i];
        }
    }
    return maxSum;
}
int main()
{
    // 原始数组
    int matrix[N][N];
    // 行数
    int rows;
    scanf("%d", &rows);
    // 初始化矩阵
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 最大子数组和
    int maxSum = INT_MIN;
    // 从每一行开始,分别求往下一行、二行、三行之和
    for (int i = 0; i < rows; i++)
    {
        // 记录相邻的几行各列之和
        int temp[N];
        memset(temp, 0, N * sizeof(int));
        for (int j = i; j < rows; j++)
        {
            // 每一列
            for (int k = 0; k < rows; k++)
            {
                temp[k] += matrix[j][k];
            }
            maxSum = max(maxSum, maxSubArraySum(temp, rows));
        }
    }
    printf("%d\n", maxSum);
    return 0;
}