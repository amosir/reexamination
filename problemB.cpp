#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool com(int a,int b){
    return a  > b;
}
int  main(){
    int rows;
    cin >> rows;
    int matrix[rows][rows];

    // 每行
    vector<int> rowEle(rows);
    // 每列
    vector<int> colEle(rows);
    // 对角线
    int slish = 0;
    for(int i = 0;i < rows;i++){
        for(int j = 0;j < rows;j++){
            int temp;
            cin >> temp;
            matrix[i][j] = temp;
        }
    }
    for(int i = 0;i < rows;i++){
        for(int j = 0;j < rows;j++){
            if(i  == j){
                slish += matrix[i][j];
            }
            rowEle[i] += matrix[i][j];
            colEle[j] += matrix[i][j];
        }
    }

    vector<int> ret(rowEle.begin(),rowEle.end());
    ret.push_back(slish);
    for(int i = 0;i < colEle.size();i++){
        ret.push_back(colEle[i]);
    }

    sort(ret.begin(),ret.end(),com);
    for(int i = 0;i < ret.size();i++){
        cout << ret[i] << " ";
    }
    return 0;
}