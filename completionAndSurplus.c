#include <stdio.h>
#define TOTAL 60
// 判断是完数还是盈数
int judge(int num)
{
    int sum = 1;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }
    if (sum == num)
    {
        return 0;
    }
    if (sum > num)
    {
        return 1;
    }
    return -1;
}
int main()
{
    // 从左向右记录完数，从右往左记录盈数
    int nums[TOTAL];
    // 完数和盈数索引
    int left = 0, right = TOTAL - 1;
    for (int i = 2; i <= 60; i++)
    {
        // 完数
        if (judge(i) == 0)
        {
            nums[left++] = i;
        }
        // 盈数
        else if (judge(i) == 1)
        {
            nums[right--] = i;
        }
    }

    printf("E: ");
    for (int i = 0; i < left; i++)
    {
        printf("%d", nums[i]);
        if (i < left - 1)
        {
            printf(" ");
        }
    }

    printf("\n");
    printf("G: ");
    for (int i = TOTAL - 1; i > right; i--)
    {
        printf("%d", nums[i]);
        if (i > right + 1)
        {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}