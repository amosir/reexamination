#include <iostream>
#include <limits.h>
#define CNT 6
using namespace std;
// 方向上右下左(x,y)
static int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
class Solution
{
private:
    // 访问状态
    bool visited[CNT][CNT];

    // 棋盘的状态
    int board[CNT][CNT];

    // 最小代价
    unsigned min_cost = INT_MAX;

    // 目标点
    int dest_x, dest_y;

public:
    void setDest(int x, int y)
    {
        dest_x = x;
        dest_y = y;
    }
    // 初始化状态
    void initBoard()
    {
        for (int i = 0; i < CNT; i++)
        {
            for (int j = 0; j < CNT; j++)
            {
                cin >> board[i][j];
                visited[i][j] = false;
            }
        }
    }

    void traverse(int x, int y, unsigned cost, int state)
    {
        if (x >= 0 && x < CNT && y >= 0 && y < CNT && !visited[x][y])
        {
            // 当前代价比最小代价小，必然不符合条件
            if (min_cost < cost)
            {
                return;
            }

            // 目标点
            if (x == dest_x && y == dest_y)
            {
                min_cost = cost;
            }
            visited[x][y] = true;

            for (int i = 0; i < 4; i++)
            {
                // 某个方向的下一步的坐标
                int new_x = x + direction[i][0];
                int new_y = y + direction[i][1];

                // 新的代价
                unsigned newcost = board[new_x][new_y] * state;

                // 新的状态
                int newstate = (newcost % 4) + 1;

                // 四个方向
                traverse(new_x, new_y, cost + newcost, newstate);
            }
            visited[x][y] = false;
        }
    }

    unsigned getCost()
    {
        return min_cost;
    }
};
int main()
{
    Solution so;
    so.initBoard();

    int start_x, start_y, end_x, end_y;
    cin >> start_x >> start_y >> end_x >> end_y;
    so.setDest(end_x, end_y);
    so.traverse(start_x, start_y, 0, 1);
    cout << so.getCost() << endl;
    return 0;
}