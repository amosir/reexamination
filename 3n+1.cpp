#include<iostream>
using namespace std;
int main(){
    int n,step = 0;
    cin >> n;
    while(n != 1){
        if((n & 1) == 0){
            n = n >> 1;
        }else{
            n = (3 * n + 1) >> 1;
        }
        step += 1;
    }
    cout << step << endl;
    return 0;
}