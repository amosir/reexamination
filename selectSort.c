// 字符串排序
#include <stdio.h>
#include <string.h>
int main()
{

    char arr[201];

    scanf("%s", arr);

    int size = strlen(arr) / sizeof(char);

    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    };

    printf("%s\n", arr);

    return 0;
}