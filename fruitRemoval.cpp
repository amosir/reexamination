#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
/**
 *  小顶堆
 */
int main(){
    int fruitType;
    while(cin >> fruitType && fruitType!=0){
        priority_queue<int,vector<int>,greater<int> > qu;
        int energy = 0;
        for(int i = 0;i < fruitType;i++){
            int cnt;
            cin >> cnt;
            qu.push(cnt);
        }
        while(qu.size() > 1){
            int fruitOne = qu.top();
            qu.pop();
            int fruitTwo = qu.top();
            qu.pop();
            energy += (fruitOne + fruitTwo);
            qu.push(fruitOne + fruitTwo);
        }

        cout << energy << endl;
        qu.pop();
    }
    return 0;
}