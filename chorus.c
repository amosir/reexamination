#include <stdio.h>
#include <string.h>
#define MAX_SIZE 101
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int stuCnt;
    while (scanf("%d", &stuCnt) != EOF && stuCnt != 0)
    {
        int heights[MAX_SIZE];
        // leftDp[i]表示heights[i]之前的最长递增序列的长度
        int leftDp[MAX_SIZE];
        // rightDp[i]表示heights[i]之后的最长递减序列的长度
        int rightDp[MAX_SIZE];

        // base case
        for (int i = 0; i < MAX_SIZE; i++)
        {
            leftDp[i] = 1;
            rightDp[i] = 1;
        }

        for (int i = 0; i < stuCnt; i++)
        {
            scanf("%d", &heights[i]);
        }

        for (int i = 0; i < stuCnt; i++)
        {
            for (int j = 0; j < i; j++)
            {
                // 0 ~ i的最长递增序列
                if (heights[j] < heights[i])
                {
                    leftDp[i] = max(leftDp[i], leftDp[j] + 1);
                }

                // x到CNT - 1的最长递减序列
                // x在y前面
                int x = stuCnt - i - 1;
                int y = stuCnt - j - 1;
                if (heights[x] > heights[y])
                {
                    rightDp[x] = max(rightDp[x], rightDp[y] + 1);
                }
            }
        }
        // 计算每一个位置前面的递增序列长度和后面的递减序列长度之和
        // 值最大时出列的学生数最少
        int maxSum = 0;
        for (int i = 0; i < stuCnt; i++)
        {
            maxSum = max(maxSum, leftDp[i] + rightDp[i]);
        }
        // studentCnt - (maxSum - 1) 减掉1是因为位置i即在递增序列，也在递减序列，加了两次
        printf("%d\n", stuCnt - maxSum + 1);
    }
    return 0;
}