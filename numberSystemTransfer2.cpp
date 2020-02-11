#include<iostream>
#include<string>
#include<algorithm>
#define MAX_NUMBER_SYSTEM 36
using namespace std;

void init(char *num_map){
    for(int i = 0;i < MAX_NUMBER_SYSTEM;i++){
        if(i <= 9){
            num_map[i] = (i + '0');
        }else{
            num_map[i] = 'A' + (i - 10);
        }
    }
}
// 获取符号对应的十进制数
int getDecimal(char ch){
    if(ch >= '0' && ch <= '9'){
        return ch - '0';
    }else{
        return ch - 'A' + 10;
    }
}
string transferTo(int from,int to,string str){
    // 初始化进制
    char num_map[MAX_NUMBER_SYSTEM];
    init(num_map);

    string result = "";
    while(!str.empty()){
        int remain = 0;
        for(int i = 0;i < str.length();i++){
            int temp = (remain * from + getDecimal(str[i]));
            char ch = temp / to >= 9 ? num_map[temp / to] : temp / to + '0';
            remain =  temp % to;
            str[i] = ch;
        }
        result.push_back(remain > 9 ? num_map[remain] : remain + '0');

        int j = 0;
        while(j < str.length() && str[j] == '0'){
            str.erase(str.begin());
        }
    }
    reverse(result.begin(),result.end());
    return result;
}
int main(){
    int from,to;
    string num;
    cin >> from >> to;
    cin >> num;
    cout << transferTo(from,to,num) << endl;
    return 0;
}