#include <stdio.h>
#include <stdlib.h>
int main()
{
    int N;
    scanf("%d", &N);
    int *arr = (int *)malloc(sizeof(int) * (N + 1));
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i < N + 1; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    printf("%d", arr[N]);
    return 0;
}