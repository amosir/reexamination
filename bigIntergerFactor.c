#include <stdio.h>
#define MAX_LEN 31
int main()
{
    // 十进制非负整数
    char decimalNum[MAX_LEN];
    // 能整除的k(2<=k<=9)
    int ks[8];
    while (scanf("%s", decimalNum) != EOF)
    {
        // 吸收缓冲区的换行符
        getchar();
        // 当前k在k的数组中的索引
        int index = 0;
        // 是否能被k整除
        int flag = 0;
        for (int k = 2; k <= 9; k++)
        {
            // x代表每一轮的余数
            int x = 0;
            for (int i = 0; decimalNum[i] != '\0'; i++)
            {
                x = (x * 10 + decimalNum[i] - '0') % k;
            }

            // 最后一次余数为0表示能被整除
            if (x == 0)
            {
                flag = 1;
                ks[index++] = k;
            }
        }

        if (flag == 1)
        {
            for (int i = 0; i < index; i++)
            {
                printf("%d", ks[i]);
                if (i < index - 1)
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        else
        {
            printf("none\n");
        }
    }
    return 0;
}