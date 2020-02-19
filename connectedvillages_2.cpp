#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct Edge{
    int village1;
    int village2;
    int cost;
    int state; // 1表示已修建,0表示未建
}Edge;
// 按照道路修建状态和代价递增排序
bool compareCost(Edge e1,Edge e2){
    // 状态相同时按代价增序
    if(e1.state == e2.state){
        return e1.cost < e2.cost;
    }else{
        // 优先已建立的
        return e1.state > e2.state;
    }
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
    while(cin >> villageCnt && villageCnt != 0){

        roadCnt = (villageCnt * (villageCnt - 1)) / 2;
        // 初始时每个村庄独立为一个集合,unionSet[0] 没用到
        // unionSet[i]表示第i个村庄
        vector<int> unionSet(villageCnt + 1,-1);

        // 保存每条道路
        vector<Edge> roads;

        for(int i = 1;i <= roadCnt;i++){
            Edge e;
            cin >> e.village1 >> e.village2 >> e.cost >> e.state;
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
                // 没建立时才计入状态
                if(roads[i].state == 0){
                    minimumCost += roads[i].cost;
                }
            }
        }

        cout << minimumCost << endl;
    }
    return 0;
}