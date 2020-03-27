#include <stdio.h>
#define MAX_SIZE 200
int main()
{
    int num;
    while (scanf("%d", &num) != EOF)
    {
        int octalNum[MAX_SIZE];
        int pos = 0;
        while (num != 0)
        {
            octalNum[pos++] = num % 8;
            num /= 8;
        }
        for (int i = pos - 1; i >= 0; i--)
        {
            printf("%d", octalNum[i]);
        }
        printf("\n");
    }
    return 0;
}