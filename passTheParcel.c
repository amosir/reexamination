#include <stdio.h>
#define MAX_SIZE 31
int main()
{
    // 参与传递的学生数和需要传递的次数
    int studentCnt, passCnt;
    scanf("%d %d", &studentCnt, &passCnt);

    // dp[i][j]表示当前在第i个同学手里,传递j次到起点(0号同学)的方法数
    int dp[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            dp[i][j] = 0;
        }
    }

    // base case
    dp[1][1] = 1;
    dp[studentCnt - 1][1] = 1;

    for (int j = 2; j <= passCnt; j++)
    {
        for (int i = 0; i <= studentCnt; i++)
        {
            // 当前在i同学手里，有两种传法:传给左边的同学或传给右边的同学
            dp[i][j] = dp[(i - 1 + studentCnt) % studentCnt][j - 1] + dp[(i + 1 + studentCnt) % studentCnt][j - 1];
        }
    }
    // 最终要求从0号同学传若干次传到自己手里的次数
    printf("%d\n", dp[0][passCnt]);
    return 0;
}