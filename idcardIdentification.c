#include <stdio.h>
static int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
static char code[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
int main()
{
    int total;
    scanf("%d", &total);
    // flag为1表示全部通过
    int flag = 1;
    for (int i = 0; i < total; i++)
    {
        char ids[19];
        // 带权和
        int temp = 0;
        scanf("%s", ids);
        int i;
        for (i = 0; i < 17; i++)
        {
            if (ids[i] < '0' || ids[i] > '9')
            {
                flag = 0;
                break;
            }
            temp += (ids[i] - '0') * weight[i];
        }

        if (i < 17)
        {
            printf("%s\n", ids);
        }
        else
        {
            if (code[temp % 11] != ids[17])
            {
                flag = 0;
                printf("%s\n", ids);
            }
        }
    }

    if (flag == 1)
    {
        printf("All passed\n");
    }
    return 0;
}