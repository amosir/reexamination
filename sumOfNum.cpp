#include<iostream>
#include<string>
using namespace std;
int main(){
    int num;
    while(cin >> num){
        string num_str = to_string(num);
        string square_str = to_string(num * num);
        int temp = 0;
        for(int i = 0;i < num_str.length();i++){
            temp += (num_str[i] - '0');
        }
        cout << temp << " ";
        temp = 0;
        for(int i = 0;i < square_str.length();i++){
            temp += (square_str[i] - '0');
        }
        cout << temp << endl;
    }
    return 0;
}