#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> circle;
    int cnt;
    cin >> cnt;
    for(int i = 1;i  <= cnt;i++){
        circle.push_back(i);
    }
    list<int>::iterator it = circle.begin();
    while(circle.size()!=1){
        int temp = 1;
        while(temp < 3){
            it++;
            if(it == circle.end()){
                it = circle.begin();
            }
            temp++;
        }
        cout << *it << " ";
        it = circle.erase(it);
        if(it == circle.end()){
            it = circle.begin();
        }
    }
    cout << circle.front() << endl;
    return 0;
}
