#include<stdio.h>
int main(){
    for(int i = 1000;i < 10000;i++){
        int temp = i * 9;
        int sum = 0;
        while(temp!=0){
            sum = sum * 10 + temp % 10;
            temp /= 10;
        }
        if(sum == i){
            printf("%d\n",i);
        }
    }
    return 0;
}