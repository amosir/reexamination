#include<iostream>
using namespace std;
/*
 * 求二进制末尾有多少个零，等价于求n!/(n-m)!中可以整除2几次， 
 * n!/(n-m)!可以写成因子乘积形式 n*(n-1)*...*(n-m+1) ，各因子可以整除2的次数之和即为所求
 */
int main(){
    int n,m;
    while(cin >> n >> m && n != 0){
        int cnt = 0;
        for(int i = n - m + 1;i <= n;i++){
            int x = i;
            while((x & 1) == 0){
                x = x >> 1;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}