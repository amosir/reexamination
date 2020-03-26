#include <stdio.h>
#define SIZE 21
int main()
{
    int number[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        number[i] = 0;
    }
    for (int i = 1; i < SIZE; i++)
    {
        int temp;
        scanf("%d", &temp);
        number[temp]++;
    }
    int max = 0;
    for (int i = 1; i < SIZE; i++)
    {
        if (number[i] > number[max])
        {
            max = i;
        }
    }
    printf("%d\n", max);
    return 0;
}