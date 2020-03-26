// 和畅通工程略有不同,处理已建立的道路时,将其cost置为0
// 或者将已建立的道路排在前面,计算代价时不计入该道路的代价
#include <stdio.h>
#define MAX_CNT 100
typedef struct Road
{
    int village1;
    int village2;
    int cost;
    int state; // 修建状态,1表示已建,0表示未建
} Road;
// 冒泡排序(按照道路代价升序)
void sortByCostAse(Road roads[], int size)
{
    for (int i = 1; i <= size - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < size - i; j++)
        {
            if (roads[j].cost > roads[j + 1].cost)
            {
                Road temp = roads[j];
                roads[j] = roads[j + 1];
                roads[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            return;
        }
    }
}
// 寻找并查集的根
int findRoot(int unionSet[], int pos)
{
    while (unionSet[pos] != -1)
    {
        pos = unionSet[pos];
    }
    return pos;
}
int main()
{
    int unionSet[MAX_CNT + 1];
    int roadCnt, villageCnt;
    while (scanf("%d", &villageCnt) != EOF && villageCnt != 0)
    {

        int totalCost = 0;
        // 保存每条道路的两个端点和代价
        Road roads[MAX_CNT * (MAX_CNT - 1) / 2];
        roadCnt = villageCnt * (villageCnt - 1) / 2;
        for (int i = 0; i < roadCnt; i++)
        {
            scanf("%d %d %d %d", &roads[i].village1, &roads[i].village2, &roads[i].cost, &roads[i].state);
            // 已经建立的道路将其代价置为0
            if (roads[i].state == 1)
            {
                roads[i].cost = 0;
            }
        }

        // 将道路按照代价排序
        sortByCostAse(roads, roadCnt);
        // 初始化并查集,并查集索引为0的位置没有使用
        for (int i = 1; i <= villageCnt; i++)
        {
            unionSet[i] = -1;
        }
        // 相连通的村庄属于一个集合
        for (int i = 0; i < roadCnt; i++)
        {
            int root1 = findRoot(unionSet, roads[i].village1);
            int root2 = findRoot(unionSet, roads[i].village2);
            if (root1 != root2)
            {
                unionSet[root1] = root2;
                totalCost += roads[i].cost;
            }
        }
        printf("%d\n", totalCost);
    }
    return 0;
}