#include<iostream>
#include<string>
using namespace std;
static int daysOfMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    int cnt;
    cin >> cnt;
    for(int i = 0;i < cnt;i++){
        int year,month,day;
        cin >> year >> month >> day;
        if((year % 400 == 0) || (year %4 == 0 && year % 100 !=0)){
            daysOfMonth[2] = 29;
        }
        // 当天不是该月的最后一天
        if(day + 1 <= daysOfMonth[month]){
            day += 1;
        }else{
            day = 1;
            // 当月不是12月
            if(month + 1 <= 12){
                month += 1;
            }else{
                month = 1;
                year+= 1;
            }
        }
        daysOfMonth[2] = 28;
        string ret = to_string(year) + "-";
        if(month < 10){
            ret+="0";
        }
        ret+=(to_string(month) + "-");
        if(day < 10){
            ret+="0";
        }
        ret+=(to_string(day));
        cout << ret << endl;
        ret.clear();
    }
    return 0;
}