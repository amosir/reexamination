#include <stdio.h>
int isPerfactNum(int num)
{
    int sum = 0;
    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0 && num != i)
        {
            sum += i;
            // i!=1那么sum/i就不可能是本身
            if (i != 1)
            {
                sum += num / i;
            }
        }
    }
    if (sum == num)
    {
        return 1;
    }

    return 0;
}
int main()
{
    int num;
    scanf("%d", &num);

    int perfact_nums[100];
    int index = -1;
    for (int i = 1; i <= num; i++)
    {
        if (isPerfactNum(i))
        {
            perfact_nums[++index] = i;
        }
    }
    for (int i = 0; i <= index; i++)
    {
        printf("%d", perfact_nums[i]);
        if (i < index)
        {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}