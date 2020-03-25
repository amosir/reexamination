#include <stdio.h>
#define CNT 10
int main()
{
    int nums[CNT];
    int oddPos = 0, evenPos = CNT - 1;
    for (int i = 0; i < CNT; i++)
    {
        int temp;
        scanf("%d", &temp);
        // 奇数从大到小排列
        if (temp % 2 != 0)
        {
            int j;
            for (j = oddPos - 1; j >= 0 && nums[j] < temp; j--)
            {
                nums[j + 1] = nums[j];
            }
            nums[j + 1] = temp;
            oddPos++;
        }
        // 偶数从小到大排列
        else
        {
            int k;
            for (k = evenPos + 1; k < CNT && nums[k] < temp; k++)
            {
                nums[k - 1] = nums[k];
            }
            nums[k - 1] = temp;
            evenPos--;
        }
    }

    for (int i = 0; i < CNT; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}