#include<iostream>
#include<string>
using namespace std;
bool isValidIPAddress(string ip){
    string temp = "";
    for(int i = 0;i < ip.length();i++){
        if(ip[i] == '.'){
            if(atoi(temp.c_str()) < 0 || 
                atoi(temp.c_str()) > 255){
                    return false;
            }
            temp = "";
        }else{
            temp += ip[i];
        }
    }
    if(atoi(temp.c_str()) < 0 ||
                atoi(temp.c_str()) > 255){
                    return false;
    }
    return true;
}
int main(){
    string ip;
    while(getline(cin,ip)){
        isValidIPAddress(ip)?cout << "Yes!" : cout << "No!" << endl;
    }
    return 0;
}