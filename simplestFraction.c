#include <stdio.h>
#define MAX_SIZE 600
int gcd(int num1, int num2)
{
    // num1始终大于num2
    if (num2 > num1)
    {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    while (num2 != 0)
    {
        int temp = num1 % num2;
        num1 = num2;
        num2 = temp;
    }
    return num1;
}
int main()
{
    int cnt;
    scanf("%d", &cnt);

    int nums[MAX_SIZE];
    for (int i = 0; i < cnt; i++)
    {
        scanf("%d", &nums[i]);
    }

    int total = 0;
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < cnt; j++)
        {
            if (nums[i] == nums[j])
            {
                continue;
            }
            // 真分数且最简
            if (nums[i] > nums[j] && gcd(nums[i], nums[j]) == 1)
            {
                total++;
            }
        }
    }
    printf("%d\n", total);
    return 0;
}