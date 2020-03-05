#include <stdio.h>
#include <stdlib.h>
#define SIZE 51
int bigFact(int num, int arr[])
{

    // 初始化
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = 0;
    }

    arr[1] = 1;
    // 阶乘值的位数
    int index = 1;

    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= index; j++)
        {
            arr[j] = arr[j] * i;
        }

        for (int k = 1; k < index; k++)
        {
            if (arr[k] > 10)
            {
                arr[k + 1] += arr[k] / 10;
                arr[k] = arr[k] % 10;
            }
        }

        while (arr[index] > 9 && index < SIZE)
        {
            arr[index + 1] += arr[index] / 10;
            arr[index] %= 10;
            index++;
        }
    }

    if (index < SIZE)
    {
        return index;
    }
    else
    {
        return 0;
    }
};
int main()
{
    int num;
    scanf("%d", &num);

    int arr[SIZE];
    int index = 0;
    if ((index = bigFact(num, arr)) == 0)
    {
        printf("溢出!\n");
    }
    else
    {
        for (int i = index; i >= 1; i--)
        {
            printf("%d", arr[i]);
        }
        printf("\n");
    }

    return 0;
}