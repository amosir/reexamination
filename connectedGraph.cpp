#include <iostream>
#include <vector>
#include <map>
using namespace std;
static int cnt = 0;
void dfs(map<int,vector<int> > graph, vector<int> &flag, int x, int vertexCnt)
{
    if (!flag[x])
    {
        flag[x] = true;
        cnt++;
        vector<int> it = graph.find(x)->second;
        for (int i = 0; i < it.size(); i++)
        {
            if (!flag[it[i]])
            {
                dfs(graph, flag, it[i], vertexCnt);
            }
        }
    }
}
int main()
{
    int vertexs, arcs;
    cin >> vertexs >> arcs;

     map<int,vector<int> > graph;
    for (int i = 0; i < vertexs; i++)
    {
       vector<int> tempVec;
       graph.insert(pair<int,vector<int> >(i,tempVec));
    }

    for(int i = 0;i < arcs;i++){
        int temp1,temp2;
        cin >> temp1  >> temp2;
        map<int,vector<int> >::iterator it1 = graph.find(temp1 - 1);
        map<int,vector<int> >::iterator it2 = graph.find(temp2 - 1);

        for(int i = 0;i < it1->second.size();i++){
                if((it1->second)[i] == temp2 - 1){
                    i--;
                    continue;
                }
            }
            it1->second.push_back(temp2 - 1);
            it2->second.push_back(temp1 - 1);
    }

    // 这里不知道为啥，用bool内存就会占完
    vector<int> visited(vertexs);
    for (int i = 0; i < vertexs; i++)
    {
        visited[i] = 0;
    }

    dfs(graph, visited, 0, vertexs);
    if(cnt == vertexs){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}