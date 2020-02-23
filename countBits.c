#include <stdio.h>
#include <string.h>
int main()
{
    char num[1001];
    int counts[10] = {0};
    scanf("%s", num);
    int len = strlen(num);
    for (int i = 0; i < len; i++)
    {
        counts[num[i] - '0']++;
    }

    for (int i = 0; i < 10; i++)
    {
        if (counts[i] != 0)
        {
            printf("%d:%d\n", i, counts[i]);
        }
    }

    return 0;
}