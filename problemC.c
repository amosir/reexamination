#include<stdio.h>
#define MAX_SIZE 100
unsigned maxPrime(unsigned num){
    int max = 0;
    for(int i = 2;i * i <=  num;i++){
        while(num % i == 0){
            num /= i;
            if(i > max){
                max = i;
            }
        }
    }
    // 如果剩下的数比max大,说明存在一个大于平方根的素数因子
    return num > max ? num : max;
}
int main(){
    int cnt;
    char str[MAX_SIZE];
    scanf("%d",&cnt);
    for(int i = 0;i < cnt;i++){
        getchar();

        // 计算字符串中的无符号数
        unsigned int num = 0;
        scanf("%s",str);
        for(int j = 0;str[j]!='\0';j++){
            if(str[j] >= '0' && str[j] <= '9'){
                num = num * 10 + str[j] - '0';
            }
        }

        printf("%d\n",maxPrime(num));
    }
    return 0;
}