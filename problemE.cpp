#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    int cnt;
    cin >> cnt;
    for(int i = 0;i < cnt;i++){
        vector<char> vec;
        string str;
        cin >> str;
        bool flag = true;
        for(int i =  0;i < str.length();i++){
            if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
                vec.push_back(str[i]);
            }
            else if(str[i] == ')'){
                if(vec.back()!='('|| vec.empty()){
                    flag = false;
                    break;
                }else{
                    vec.pop_back();
                }
            }else if(str[i] == ']'){
                if(vec.back()!='['|| vec.empty()){
                    flag = false;
                    break;
                }else{
                    vec.pop_back();
                }
            }else if(str[i] == '}'){
                if(vec.back()!='{'|| vec.empty()){
                    flag = false;
                    break;
                }else{
                    vec.pop_back();
                }
            }
        } 
        if(!flag){
            cout  << "no" << endl;
        }else{
            cout << "yes" << endl;
        }
    }
    return 0;
}
