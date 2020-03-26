#include <stdio.h>
int main()
{
    int cnt;
    while (scanf("%d", &cnt) != EOF)
    {
        int oddCnt = 0, evenCnt = 0;
        for (int i = 0; i < cnt; i++)
        {
            int temp;
            scanf("%d", &temp);
            if ((temp & 1) == 0)
            {
                evenCnt++;
            }
            else
            {
                oddCnt++;
            }
        }
        if (evenCnt > oddCnt)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}