#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    vector<char> encryption(26);
    for(int i = 0;i < 26;i++){
        encryption[i] = (i - 5 + 26) % 26 + 'A';
    } 
    
    string str;
    while(getline(cin,str)){
        if(str == "ENDOFINPUT"){
            return 0;
        }
        if(str == "START" || str == "END"){
            continue;
        }else{
            for(int i = 0;i < str.length();i++){
                if(str[i] >= 'A' && str[i] <= 'Z'){
                    str[i] = encryption[str[i] - 'A'];
                }
            }
            cout << str << endl;
        }

    }
    return 0;
}
