#include <stdio.h>
#include <string.h>
#define PROXYS_MAX 1000
#define SERVERS_MAX 5000
#define IP_LEN 16
int main()
{
    // 代理服务器和服务器地址
    char proxys[PROXYS_MAX][IP_LEN];
    char servers[SERVERS_MAX][IP_LEN];

    // 服务器数和代理服务器数
    int serverCnt, proxyCnt;

    scanf("%d", &proxyCnt);
    for (int i = 0; i < proxyCnt; i++)
    {
        scanf("%s", proxys[i]);
    }
    scanf("%d", &serverCnt);
    for (int i = 0; i < serverCnt; i++)
    {
        scanf("%s", servers[i]);
    }

    // start表示当前代理开始的服务器索引，changes表示转换次数
    // flag表示是否匹配成功
    int start = 0, changes = 0, flag = 1;

    while (flag && start < serverCnt)
    {
        int max = 0;

        // 从代理服务器中选中一个，用它尽可能多的代理
        for (int i = 0; i < proxyCnt; i++)
        {
            // 每次从index开始访问
            int j = start;
            while (j < serverCnt && strcmp(proxys[i], servers[j]))
            {
                j++;
            }

            // 选择代理数最多的
            if (j - start > max)
            {
                max = j - start;
            }
        }

        // 代理数最多是0表示该服务器无法代理，代理失败
        if (max == 0)
        {
            flag = 0;
        }
        changes++;
        start += max;
    }
    if (flag == 0)
    {
        printf("-1\n");
    }
    else
    {
        // 第一次不用转换
        printf("%d\n", changes - 1);
    }
    return 0;
}