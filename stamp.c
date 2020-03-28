#include<stdio.h>
#define SIZE 100
int main()
{
    int set[SIZE];
    int top = -1;
    for(int i = 0;i < SIZE;i++){
        set[i] = -1;
    }
    // 8角的5张
    for (int i = 0; i <= 5; i++)
    {
        // 一元的4张
        for (int j = 0; j <= 4; j++)
        {
            // 一元八角的6张
            for (int k = 0; k <= 6; k++)
            {
                int total = 8 * i + 10 * j + 18 * k;
                // 该值是否出现过
                int flag = 0;
                for(int r = 0;r <= top;r++){
                    if(set[r] == total){
                        flag = 1;
                        break;
                    }
                }
                // 没有出现过的组合入栈
                if(flag == 0 && total != 0){
                    set[++top] = total;
                }
            }
        }
    }
    printf("%d\n",top + 1);
    return 0;
}