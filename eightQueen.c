#include <stdio.h>
#define QUEEN_CNT 8

// 是否可放置皇后
int canLay(int chessboard[], int x, int y)
{
    // 同一列是否有冲突
    for (int i = 0; i < x; i++)
    {
        if (chessboard[i] == y)
        {
            return 0;
        }
    }

    // 主对角线是否有冲突
    for (int i = 0; i < x; i++)
    {
        if (x - i == y - chessboard[i])
        {
            return 0;
        }
    }

    // 副对角线是否有冲突
    for (int i = 0; i < x; i++)
    {
        if (x - i == chessboard[i] - y)
        {
            return 0;
        }
    }

    return 1;
}

// 在第row行放置皇后
// needed表示需要打印的第几种放置方式
// count表示当前已经有多少种放置方式
void placeQueen(int chessboard[], int row, int *needed, int *count)
{
    // 完成一种放置
    if (row == QUEEN_CNT)
    {
        (*count)++;
        // 之所以直接打印是因为每一行放置时都是从第0列开始的
        // 这样保证放置的列是从小到大排列的
        if (*count == *needed)
        {
            for (int i = 0; i < QUEEN_CNT; i++)
            {
                // 计算时列从0开始，输出时从1开始
                printf("%d", chessboard[i] + 1);
            }
            printf("\n");
        }
        return;
    }
    else
    {
        for (int j = 0; j < QUEEN_CNT; j++)
        {
            // 如果该列可以放置
            if (canLay(chessboard, row, j))
            {
                // 放置皇后
                chessboard[row] = j;
                placeQueen(chessboard, row + 1, needed, count);
                // 还原该位置
                chessboard[row] = -1;
            }
        }
    }
}
int main()
{
    // 输出第几个串
    int order;
    scanf("%d", &order);
    // j = chessboard[i]表示(i,j)放置皇后
    int chessboard[QUEEN_CNT];

    // 初始化棋盘
    for (int i = 0; i < QUEEN_CNT; i++)
    {
        chessboard[i] = -1;
    }

    // 记录已经放置成功的方式
    int count = 0;
    // 从第0行开始放置皇后
    placeQueen(chessboard, 0, &order, &count);
    return 0;
}