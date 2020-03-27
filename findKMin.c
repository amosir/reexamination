#include <stdio.h>
#include <string.h>
#define MAX 1001
int main()
{
    int cnt;
    scanf("%d", &cnt);

    // numCount[i]表示i的出现次数
    int numCount[MAX];
    memset(numCount, 0, sizeof(int) * MAX);
    for (int i = 0; i < cnt; i++)
    {
        int temp;
        scanf("%d", &temp);
        numCount[temp]++;
    }

    int k;
    scanf("%d", &k);

    int order = 1;

    for (int j = 1; j < MAX; j++)
    {
        if (numCount[j] != 0)
        {
            if (order == k)
            {
                printf("%d\n", j);
                return 0;
            }
            else
            {
                order++;
                continue;
            }
        }
    }
    return 0;
}