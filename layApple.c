#include <stdio.h>
#define MAX_CNT 11
/**
 * 
 * 1、当只有一个盘子或者 含有 0 个 或 1 个苹果的时候只有一种方法
 * 2、当盘子数 n 大于苹果数 m 时，则必有 n - m 个空盘子，所以只需求 m 个盘子
   放 m 个苹果时的方法数即可，
   3、当盘子数 n 小于等于 苹果数 m 时，总方法数 = 当含有一个空盘子时的方法数
  + 不含空盘子时的方法数。
 */
int main()
{
    int appleCnt, dishCnt;
    scanf("%d %d", &appleCnt, &dishCnt);

    // dp[i][j] 表示i个苹果放到j个篮子里面
    int dp[MAX_CNT][MAX_CNT];

    // 只有一个篮子时只有一种方法
    for (int i = 0; i <= appleCnt; i++)
    {
        dp[i][1] = 1;
    }

    // 只有一个苹果或者没有苹果时只有一种方法
    for (int j = 0; j <= dishCnt; j++)
    {
        dp[0][j] = 1;
        dp[1][j] = 1;
    }
    for (int i = 2; i <= appleCnt; i++)
    {
        for (int j = 2; j <= dishCnt; j++)
        {
            // 篮子数大于苹果数时
            if (j > i)
            {
                dp[i][j] = dp[i][i];
            }
            // 篮子数小于等于苹果数时:
            // 分所有篮子都放和至少一个篮子不放两种情况
            else
            {
                dp[i][j] = dp[i][j - 1] + dp[i - j][j];
            }
        }
    }
    printf("%d\n", dp[appleCnt][dishCnt]);
    return 0;
}