#include <stdio.h>
int main()
{
    int limit, sum = 0;
    scanf("%d", &limit);
    for (int i = 1; i <= limit; i++)
    {
        // 是否与7无关
        int flag = 0;
        // 是否是7的倍数
        if (i % 7 == 0)
        {
            flag = 1;
        }
        else
        {
            // 位中是否含有7
            int j = i;
            while (j != 0)
            {
                int temp = j % 10;
                if (temp == 7)
                {
                    flag = 1;
                    break;
                }
                j /= 10;
            }
        }
        if (flag == 0)
        {
            sum += i * i;
        }
    }
    printf("%d\n", sum);
    return 0;
}