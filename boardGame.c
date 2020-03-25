#include <stdio.h>
#include <string.h>
#include <limits.h>
#define ROWS 6
// (x,y)表示该步横纵坐标的变化,按照上右下左
static int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
// 当前最小代价
static int mincost = INT_MAX;
// 访问标记数组
static int flag[ROWS][ROWS];
// 棋盘
static int board[ROWS][ROWS];
// 当前正访问(x,y),状态时state,这一步代价是cost
void traverseBoard(int x, int y, int endX, int endY, int state, int cost)
{
    if (x >= 0 && x < ROWS && y >= 0 && y < ROWS && !flag[x][y])
    {
        // 如果当前cost比mincost还大,必然不会是代价最小的
        if (cost > mincost)
        {
            return;
        }
        // 当前访问到目标坐标并且代价更小则更新
        if (x == endX && y == endY)
        {
            mincost = cost;
        }

        // 设置为已访问
        flag[x][y] = 1;
        // 往四个方向移动
        for (int i = 0; i < 4; i++)
        {
            // 移动后的新坐标
            int newX = x + direction[i][0];
            int newY = y + direction[i][1];
            // 这一步代价
            int newCost = state * board[newX][newY];
            // 新状态
            int newState = newCost % 4 + 1;
            traverseBoard(newX, newY, endX, endY, newState, cost + newCost);
        }
        // 还原访问标记
        flag[x][y] = 0;
    }
}
int main()
{
    // 棋盘上每个位置的值
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    // 初始化访问标记
    memset(flag, 0, sizeof(int) * ROWS * ROWS);

    int startX, startY, endX, endY;
    scanf("%d %d %d %d", &startX, &startY, &endX, &endY);
    traverseBoard(startX, startY, endX, endY, 1, 0);
    printf("%d\n", mincost);
    return 0;
}