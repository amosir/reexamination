#include <stdio.h>
#define MAX_LEN 10001
int main()
{
    // 长度和区间数
    int len, rangeCnt;
    int trees[MAX_LEN];
    scanf("%d %d", &len, &rangeCnt);
    // 一共len + 1棵树
    for (int i = 0; i <= len; i++)
    {
        trees[i] = 1;
    }
    for (int j = 0; j < rangeCnt; j++)
    {
        // 移出区间内的树
        int start, end;
        scanf("%d %d", &start, &end);
        for (int k = start; k <= end; k++)
        {
            trees[k] = 0;
        }
    }

    // 没有被移出的树
    int remain = 0;
    for (int r = 0; r <= len; r++)
    {
        if (trees[r] == 1)
        {
            remain++;
        }
    }
    printf("%d\n", remain);
    return 0;
}