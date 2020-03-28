#include<stdio.h>
#define MAX 256
// 是否是对称平方数
int isSymmetricSquareNum(int num){
    int square = num * num;
    int temp = square;
    //  sum是square逆置后的数
    int sum = 0;
    while(temp != 0){
        sum = sum * 10 + temp % 10;
        temp /= 10;
    }
    if(square == sum){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    for(int i = 0;i <= MAX;i++){
        if(isSymmetricSquareNum(i) == 1){
            printf("%d\n",i);
        }
    }
    return 0;
}