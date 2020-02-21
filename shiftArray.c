#include <stdio.h>
#include <stdlib.h>
void shiftArray(int *arr, int start, int end)
{
    while (start < end)
    {
        arr[start] = arr[start] ^ arr[end];
        arr[end] = arr[end] ^ arr[start];
        arr[start] = arr[start] ^ arr[end];
        start++;
        end--;
    }
}
int main()
{
    int eleCnt, shiftCnt;
    scanf("%d %d", &eleCnt, &shiftCnt);
    int *arr = (int *)malloc(sizeof(int) * eleCnt);

    for (int i = 0; i < eleCnt; i++)
    {
        scanf("%d", &arr[i]);
    }

    shiftCnt %= eleCnt;

    shiftArray(arr, 0, eleCnt - 1);
    shiftArray(arr, 0, shiftCnt - 1);
    shiftArray(arr, shiftCnt, eleCnt - 1);

    for (int i = 0; i < eleCnt; i++)
    {
        printf("%d", arr[i]);
        if (i < eleCnt - 1)
        {
            printf(" ");
        }
    }

    return 0;
}