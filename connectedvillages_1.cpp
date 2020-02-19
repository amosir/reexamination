#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct Edge{
    int village1;
    int village2;
    int cost;
}Edge;
// 按照道路代价递增排序
bool compareCost(Edge e1,Edge e2){
    return e1.cost < e2.cost;
}
// 寻找根节点
int findRoot(vector<int> unionSet,int village){
    if(unionSet[village] == -1){
        return village;
    }else{
        village = findRoot(unionSet,unionSet[village]);
    }
    return village;
}
int main(){

    // 道路数,村庄数、最小代价
    int roadCnt,villageCnt,minimumCost = 0;
    while(cin >> roadCnt >> villageCnt && villageCnt != 0){
        // 初始时每个村庄独立为一个集合,unionSet[0] 没用到
        // unionSet[i]表示第i个村庄
        vector<int> unionSet(villageCnt + 1,-1);

        // 保存每条道路
        vector<Edge> roads;

        for(int i = 1;i <= roadCnt;i++){
            Edge e;
            cin >> e.village1 >> e.village2 >> e.cost;
            roads.push_back(e);
        }

        // 按代价增序排序，这样就能优先选中代价小的道路
        sort(roads.begin(),roads.end(),compareCost);

        for(int i = 0;i < roadCnt;i++){

            int root1 = findRoot(unionSet,roads[i].village1);
            int root2 = findRoot(unionSet,roads[i].village2);
            // 如果两个村庄没有路径
            if(root1!=root2){
                unionSet[root1] = root2;
                minimumCost += roads[i].cost;
            }
        }

        // unionSet等于-1表示没有互联
        int neededRoad = 0;
        for(int i = 1;i <= villageCnt;i++){
            if(unionSet[i]==-1){
                neededRoad += 1;
            }
        }

        // 若所有的村庄都互联那么最终只有根节点
        // 的unionSet值为-1，其他的都不是-1
        if(neededRoad != 1){
            cout << "?" << endl;
        }else{
            cout << minimumCost << endl;
        }
    }
    return 0;
}