#include <stdio.h>
#define MAX_CNT 80
int main()
{
    // 输入整数
    int nums[MAX_CNT];
    // 记录极值点坐标
    int records[MAX_CNT];
    int cnt;
    while (scanf("%d", &cnt) != EOF)
    {
        int index = 0;
        for (int i = 0; i < cnt; i++)
        {
            scanf("%d", &nums[i]);
        }

        // 寻找极值点坐标
        for (int j = 0; j < cnt; j++)
        {
            // 首末两个位置的元素
            if ((j == 0 && nums[j] != nums[j + 1]) || (j == cnt - 1 && nums[cnt - 1] != nums[cnt - 2]))
            {
                records[index++] = j;
            }
            // 中间的元素
            else
            {
                if ((nums[j] > nums[j - 1] && nums[j] > nums[j + 1]) ||
                    (nums[j] < nums[j - 1] && nums[j] < nums[j + 1]))
                {
                    records[index++] = j;
                }
            }
        }

        // 输出
        for (int k = 0; k < index; k++)
        {
            printf("%d", records[k]);
            if (k < index - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
