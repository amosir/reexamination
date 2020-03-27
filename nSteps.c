#include <stdio.h>
#define MAX_SIZE 91
int main()
{
    int N;
    scanf("%d", &N);
    // dp[i]表示i阶楼梯的上楼方式
    int dp[MAX_SIZE];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < N + 1; i++)
    {
        // 最后一步可以走1步或2步
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    printf("%d", dp[N]);
    return 0;
}