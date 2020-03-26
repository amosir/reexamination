// 交换最大最小数
#include <stdio.h>
#define MAX_SIZE 20
int main()
{
    int arr[MAX_SIZE];
    int n = 0;

    scanf("%d", &n);

    int minIndex = 0, maxIndex = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }

        if (arr[i] > arr[maxIndex])
        {
            maxIndex = i;
        }
    }

    int temp = arr[minIndex];
    arr[minIndex] = arr[maxIndex];
    arr[maxIndex] = temp;

    for (int j = 0; j < n; j++)
    {
        printf("%d", arr[j]);
        if (j < n - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}