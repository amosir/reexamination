#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
// 将字符串分割成任务名
vector<string> split_string(string str){
    vector<string> vec;
    int len = str.length();
    string temp = "";
    for(int i = 0;i < len;i++){
        if(str[i]!=')' && str[i]!='(' && str[i]!=','){
            temp.push_back(str[i]);
        }else{
            vec.push_back(temp);
            temp = "";
        }
    }
    if(temp!=""){
        vec.push_back(temp);
    }
    return vec;
}

// 根据字符串填充图
void buildTaskMap(map<string,vector<string> > &taskMap,string str){
    vector<string> vec = split_string(str);

    for(int i = 1;i < vec.size();i++){
        if(vec[i]!="NULL"){
            // 图
            map<string,vector<string> >::iterator it = taskMap.find(vec[0]);
            if(it == taskMap.end()){
                vector<string> temp;
                temp.push_back(vec[i]);
                taskMap.insert(pair<string,vector<string> >(vec[0],temp));
            }else{
                it->second.push_back(vec[i]);
            }
        }else{
            map<string,vector<string> >::iterator it = taskMap.find(vec[0]);
            vector<string> temp;
            taskMap.insert(pair<string,vector<string> >(vec[0],temp));
            
        }
    }
}

vector<string> findTaskSchedule(map<string,vector<string> > &taskMap){
    // 返回最后的结果
    vector<string> retVec;
    // 入度表
    map<string,int> indegree;
    // 保存入度为0的节点
    vector<string> in0;
    // 填充入度表
    for(map<string,vector<string> >::iterator it = taskMap.begin();it!=taskMap.end();it++){
        map<string,int>::iterator tempIt = indegree.find(it->first);
        if(tempIt == indegree.end()){
            indegree.insert(pair<string,int>(it->first,0));
        }
        for(int i = 0;i < it->second.size();i++){
            tempIt = indegree.find((it->second)[i]);
            if(tempIt!=indegree.end()){
                (tempIt->second)++;
            }else{
                indegree.insert(pair<string,int>((it->second)[i],1));
            }
        }
    }

    // 初始化入度为0的数组
    map<string,int>::iterator it = indegree.begin();
    while(it->second == 0 && it!=indegree.end()){
        in0.push_back(it->first);
        it++;
    }

    // 拓扑排序
    while(!in0.empty()){
        sort(in0.begin(),in0.end());
        retVec.push_back(in0[0]);
        vector<string> vec = taskMap.find(in0[0])->second;
        for(int i = 0;i < vec.size();i++){
            int in = --(indegree.find(vec[i])->second);
            if(in == 0){
                in0.push_back(vec[i]);
            }
        }
        in0.erase(in0.begin());
    }
    return retVec;
}

int main(){
    map<string,vector<string> > taskMap;
    int cnt;
    cin >> cnt;
    for(int i = 0;i < cnt;i++){
        string temp;
        cin >> temp;
        buildTaskMap(taskMap,temp);
    }
    vector<string> vec = findTaskSchedule(taskMap);
    for(int i = 0;i < vec.size();i++){
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}
