#include <stdio.h>
static int numArr[3] = {0};
int main()
{
    int num, pos = 0;
    scanf("%d", &num);

    // 从低位到高位，依次保存在数组低位到高位
    while (num != 0)
    {
        numArr[pos++] = num % 10;
        num /= 10;
    }
    pos--;
    while (pos >= 0)
    {
        // 百位
        if (pos == 2)
        {
            for (int i = 0; i < numArr[pos]; i++)
            {
                printf("B");
            }
        }
        // 十位
        else if (pos == 1)
        {
            for (int i = 0; i < numArr[pos]; i++)
            {
                printf("S");
            }
        }
        // 个位
        else if (pos == 0)
        {
            for (int i = 0; i < numArr[pos]; i++)
            {
                printf("%d", i + 1);
            }
        }
        pos--;
    }

    return 0;
}