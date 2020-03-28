#include<stdio.h>
#define MAX_SIZE 1000010
// 寻找并查集某一个元素的根
int findRoot(int unionSet[],int node){
    while(unionSet[node]!=-1){
        node = unionSet[node];
    }
    return node;
}
int main(){
    // 标记数组,表示该数是否出现过
    int flag[MAX_SIZE];
    // 并查集
    int unionSet[MAX_SIZE];
    //  初始化
    for(int i = 0;i < MAX_SIZE;i++){
        flag[i] = 0;
        unionSet[i] = -1;
    }
    int node_i,node_j;
    while(scanf("%d %d",&node_i,&node_j)!=EOF){
        int root1 = findRoot(unionSet,node_i);
        int root2 = findRoot(unionSet,node_j);
        if(root1 != root2){
            unionSet[root1] = root2;
        }
        flag[node_i] = 1;
        flag[node_j] = 1;
    }

    // 统计分支数
    int count = 0;
    for(int i = 0;i < MAX_SIZE;i++){
        if(flag[i] == 1 && unionSet[i] == -1){
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}