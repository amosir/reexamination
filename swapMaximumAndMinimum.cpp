// 交换最大最小数
#include <stdio.h>

int main()
{

    int arr[20];

    int n = 0;

    scanf("%d", &n);

    if (n >= 1 && n <= 20)
    {
        int min = 0, max = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            if (arr[i] < arr[min])
            {
                min = i;
            }

            if (arr[i] > arr[max])
            {
                max = i;
            }
        }

        int temp = arr[min];
        arr[min] = arr[max];
        arr[max] = temp;

        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }

    return 0;
}