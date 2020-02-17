#include<iostream>
using namespace std;
int main(){
    int totalCnt;
    cin >> totalCnt;

    int ageSum = 0;
    for(int i = 0;i < totalCnt;i++){
        int temp;
        cin >> temp;
        ageSum += temp;
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << (double)ageSum / totalCnt << endl;
    return 0;
}